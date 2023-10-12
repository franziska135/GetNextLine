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

char	*ft_strjoin(char *src, char *dest)
{
	int		i;
	int		j;
	int		total_size;
	char	*newstr;

	i = 0;
	j = 0;
	total_size = ft_strlen2(src) + ft_strlen2(dest);
	// if (newstr)
	// 	free(newstr);
	newstr = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!newstr)
		return (free(newstr), free(src), free(dest), NULL);
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	while (dest[j] != '\0')
	{
		newstr[i + j] = dest[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
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

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
