/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:24:59 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/09 12:25:01 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *src, char *to_add)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (to_add[j])
		src[i++] = to_add[j++];
	src[i] = to_add[j];
	return (src);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\n' || string[i] == '\0')
		i++;
	return (i);
}
