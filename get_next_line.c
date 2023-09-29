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
//read(fd, buffer size, nbr_of_bytes)
//storebuffer in static stash
//check if in stash a \n stored
//if \n than extract everything up until \n in another variable
//remove this from static stash_
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	t_list	*storage;
	char			*line;
	int				gelesen;

	/*if prolem with opening fd: -1*/
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	storage = NULL
	gelesen = 1;
	line = NULL;
	//read from fd, add to linked list
	read_fd_to_storage()
	//extract from stash to line
	//clean up stash
	retun(line);
}
