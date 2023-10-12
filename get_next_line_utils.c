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

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcpy(char *dest, char *src, char c, int start)
{
	int	i;

	i = 0;
	while (src[start + i] != '\0' && src[start + i] != c)
	{
		dest[i] = src[start + i];
		i++;
	}
	return (i);
}

int	ft_newline(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *old, char *to_add)
{
	char	*joined;
	int		i;
	int		j;
	int		total_size;

	total_size = ft_strlen(old, '\0') + ft_strlen(to_add, '\0');
	if (!old)
	{
		old = (char *)malloc(1 * sizeof(char));
		if (!old)
			return (free(to_add), NULL);
		old[0] = '\0';
	}
	if (!old || !to_add)
		return (NULL);
	joined = (char *)malloc(1 + total_size * sizeof(char));
	if (!joined)
		return (free(old), free(to_add), NULL);
	i = ft_strcpy(joined, old, '\0', 0);
	j = -1;
	while (to_add && to_add[++j])
		joined[i + j] = to_add[j];
	joined[i + j] = '\0';
	free(old);
	return (joined);
}
