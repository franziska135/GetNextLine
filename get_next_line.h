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
/*define a buffer if no argv is given*/
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# include BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# define FALSE 0

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

#endif