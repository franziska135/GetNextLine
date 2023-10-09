/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:21:23 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/29 11:21:26 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// read will return the number of bytes read -> compare with expected value for protection?
// if read returns 0, the end of file is reached
// read -1 if error
//read(fd, buffer size, nbr_of_bytes)
//if storage is still empty after reading
//copy from storage to line
//clean up storage
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*storage;
	char			*output;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &output, 0) < 0)
		return (NULL);
	storage = NULL;
	output = NULL;
	read_to_temp(fd, &storage);
	if (storage == NULL)
		return (NULL);
	storage_to_output(&storage, output);
	free_storage(&storage);
	if (output[0] == '\0')
	{
		free_storage(&storage);
		storage = NULL;
		free(output);
		return (0);
	}
	return (output);
}

void	read_to_temp(int fd, t_list **storage)
{
	char	*temp;
	int		i;

	i = 1;
	while (newline(storage) == 0 && i != 0)
	{
		temp = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
		if (!temp)
			return ;
		i = (int)read(fd, temp, BUFFER_SIZE);
		temp[i] = '\0';
		if ((storage == NULL && i == 0) || i == -1)
		{
			free(temp);
			return ;
		}
		temp_to_storage(storage, temp, i);
		free(temp);
	}
}

//add content of temp to end of storage
//copy content of temp to new_node
//add new_node to end of structure
//if structure is empty, add new_node
void	temp_to_storage(t_list **storage, char *temp, int gelesen)
{
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(sizeof(char) * (gelesen + 1));
	if (new_node->content == NULL)
		return ;
	new_node->next = NULL;
	ft_strcpy(temp, new_node->content, gelesen);
	if (storage != NULL)
	{
		last_node = *storage;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	else
		storage = &new_node;
	return ;
}

/*chars from storage to output and stop at \n*/
void	storage_to_output(t_list **storage, char *output)
{
	int	i;
	int	j;
	int	length;
	t_list	*doublicate;

	doublicate = *storage;
	length = count_length(*storage);
	output = malloc(sizeof(char) * (length + 1));
	if (output == NULL || *storage == NULL)
		return ;
	j = 0;
	while (doublicate != NULL)
	{
		i = 0;
		while (doublicate->content[i])
		{
			if (doublicate->content[i] == '\n')
			{
				output[j++] = doublicate->content[i];
				return ;
			}
			output[j++] = doublicate->content[i++];
		}
		doublicate = doublicate->next;
	}
	output[j] = '\0';
}

/*after extracting the line that was read, 
clearing storage and only chars that have not been read at the end of
gnl remain for next function call*/

void	free_storage(t_list **storage)
{
	t_list	*last;
	t_list	*new_node;
	int		i;
	int		j;

	new_node = malloc(sizeof(t_list));
	if (storage == NULL || new_node == NULL)
		return ;
	new_node->next = NULL;
	while ((*storage)->next != NULL)
		*storage = (*storage)->next;
	last = *storage;
	i = count_length(last);
	new_node->content = malloc(sizeof(char) * (i + 1));
	if (new_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		new_node->content[j++] = last->content[i++];
	new_node->content[j] = '\0';
	ft_free(*storage);
	storage = &new_node;
}

int	main(void)
{
	int 	file;
	char	*str;

	file = open("abc.txt", O_RDONLY);
	if (file == -1)
	{
		printf("Error in opening the file");
		return (0);
	}
	str = get_next_line(file);
	while (str)
	{
		printf("first line: \t%s", str);
		free (str);
		str = get_next_line(file);
	}
	if (str == NULL)
		printf("NULL");
	free(str);
	close(file);
	return (0);
}