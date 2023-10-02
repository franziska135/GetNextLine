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
	int				gelesen;

	/*if prolem with opening fd: -1*/
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	storage = NULL; //initializing list with NULL
	gelesen = 1;
	//line = NULL;
	/*read from fd, add to linked list storage*/
	read_buffer_storage(fd, &storage, &gelesen);
	if (storage == NULL) /*if file is empty*/
		return (NULL); 
	/*copy from storage to line*/
	ft_extract_line(storage, &line);
	//clean up storage
	ft_clean_storage(&storage);
	if (line[0] == '\0')
	{
		free_storage(storage);
		storage = NULL;
		free(line);
		return (0);
	}
	return (line);
}

void	read_buffer_storage(int fd, t_list **storage, int *ptr_gelesen)
{
	char	*buffer;

	while (ft_newline(*storage) == FALSE && *ptr_gelesen != NULL)
	{
		buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
		if (!buffer)
			return ;
		*ptr_gelesen = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*storage == NULL && *ptr_gelesen == 0) || *ptr_gelesen == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*ptr_gelesen] = '\0';
		ft_buffer_to_storage(storage, buffer, *ptr_gelesen);
		free(buffer);
	}
}

/*adding content of buffer to end of storage*/
void	ft_buffer_to_storage(t_list **storage, char *buffer, int gelesen)
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
	while (buffer[i] && i < gelesen)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*storage == NULL)
	{
		*storage = new_node;
		return ;
	}
	last_node = retreive_last_node(*storage);
	last_node->next = new_node;
}

/*extracting characers from storage, storing them on line*/
/*stopping after the first \n*/
void	extract_line(t_list *storage, char **line)
{
	int	i;
	int	j;
	/*if nothing to extract*/
	if (storage == NULL)
		return ;
	generate_line(line, storage);
	if (*line == NULL)
		return ;
	j = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			if (storage->content[i] == '\n')
			{
				(*line)[j++] = storage->content[i];
				break ;
			}
			(*line)[j++] = storage->content[i++];
		}
		storage = storage->next;
	}
	(*line)[j] = '\0';
}

/*after extracting the line that was read, no chars a needed anymore
clearing storage so only chars that have not been returned at the end of
gnl remain in static stash*/
void	clean_stash()
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