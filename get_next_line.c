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
/*read will return the number of bytes read -> compare with expected value for protection?*/
/*if read returns 0, the end of file is reached*/
/*read -1 if error*/
//read(fd, buffer size, nbr_of_bytes)
//storebuffer in static stash
//check if in stash a \n stored
//if \n than extract everything up until \n in another variable
//remove this from static stash_
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*storage;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	storage = NULL;
	line = NULL;
	read_buffer_storage(fd, &storage);
	//if storage is still empty after reading
	if (storage == NULL)
		return (NULL);
	//copy from storage to line
	extract_line(storage, &line);
	//clean up storage
	free_storage(&storage);
	if (line[0] == '\0')
	{
		free_storage(storage);
		storage = NULL;
		free(line);
		return (0);
	}
	return (line);
}

void	read_buffer_storage(int fd, t_list *storage)
{
	char	*temp;
	int		gelesen;

	gelesen = 1;
	//why does newline only need the last node?
	//check if the || condition is correct
	while (newline(&storage) == 1 && gelesen != 0)
	{
		temp = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
		if (!temp)
			return ;
		gelesen = (int)read(fd, temp, BUFFER_SIZE);
		if ((storage == NULL && gelesen == 0) || gelesen == -1)
		{
			free(temp);
			return ;
		}
		temp[gelesen] = '\0';
		ft_buffer_to_storage(&storage, temp, gelesen);
		free(temp);
	}
}

/*adding content of buffer to end of storage*/
void	ft_buffer_to_storage(t_list *storage, char *temp, int gelesen)
{
	int		i;
	t_list	*last_node;
	t_list	*new_node;

	i = 0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = malloc(sizeof(char) * (gelesen + 1));
	if (new_node->content == NULL)
		return ;
	new_node->next = NULL;
	//insert strlcpy
	while (temp[i] && i < gelesen)
	{
		new_node->content[i] = temp[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (storage != NULL)
	{
		last_node = retrieve_last_node(*storage);
		last_node->next = new_node;
	}
	else
		storage = new_node;
	return ;
}

/*extracting characers from storage, storing them on line*/
/*stopping after the first \n*/
void	extract_line(t_list *storage, char *line)
{
	int	i;
	int	j;
	int	len;

	len = count_length(storage);
	line = malloc(sizeof(char) * (len + 1));
	if (!line || storage == NULL)
		return ;
	j = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			if (storage->content[i] == '\n')
			{
				line[j++] = storage->content[i];
				break ;
			}
			line[j++] = storage->content[i++];
		}
		storage = storage->next;
	}
	line[j] = '\0';
}

/*after extracting the line that was read, no chars a needed anymore
clearing storage so only chars that have not been returned at the end of
gnl remain in static stash*/
void	free_storage()
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (storage == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_kast(*storage);
	i = 0;
	while (last->content[i] && last->contetnt[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - 1) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_storage(*storage);
	*storage = clean_node;
}