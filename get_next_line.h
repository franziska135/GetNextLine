/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:25:10 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/09 12:25:11 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_newline(char *string);
// char	*ft_join(char *dest, char *s1, char *s2);
// char	*ft_extract_remnant(char *storage);
// // int		ft_strlen(char *string);
// int		ft_strlen2(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_storage_to_output(char *storage);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *storage, char *new_string);
int		ft_inclusive_strlen(char *str);

#endif
