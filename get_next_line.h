/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:21:43 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/29 11:21:45 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_to_temp(int fd, t_list **storage);
void	temp_to_storage(t_list **storage, char *temp, int gelesen);
void	storage_to_output(t_list **storage, char *output);
void	free_storage(t_list **storage);
int		newline(t_list **storage);
void	ft_strcpy(char *src, char *dest, int gelesen);
int		count_length(t_list *storage);
void	ft_free(t_list *storage);
int		ft_slen(const char *str);


#endif