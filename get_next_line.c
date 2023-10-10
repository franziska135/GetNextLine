/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:24:32 by fmarggra          #+#    #+#             */
/*   Updated: 2023/10/09 12:24:35 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*output;
	static char	*storage;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!storage)
	{
		storage = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!storage)
			return (0);
	}
	storage = ft_read_to_storage(fd, storage);
	if (storage == 0)
		return (NULL);
	output = ft_storage_to_output(storage, output);
	storage = ft_extract_remnant(storage);
	return (output);
}

char	*ft_read_to_storage(int fd, char *storage)
{
	int		gelesen;
	char	*new_string;

	while (ft_newline(storage) == 0)
	{
		new_string = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (!new_string)
			return (0);
		gelesen = read(fd, new_string, BUFFER_SIZE);
		if (gelesen == -1 || gelesen == 0)
		{
			if (gelesen == 0)
			{
				free(new_string);
				free(storage);
			}
			return (0);
		}
		storage = ft_strjoin(storage, new_string);
		free(new_string);
	}
	return (storage);
}

char	*ft_storage_to_output(char *storage, char *output)
{
	int	i;

	i = ft_strlen(storage);
	output = (char *)malloc(sizeof(char) * (i + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		output[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n' || storage[i] == '\0')
		output[i] = storage[i];
	output[++i] = '\0';
	return (output);
}

char	*ft_extract_remnant(char *storage)
{
	int		i;
	int		j;
	char	*remnant_string;

	i = 0;
	j = 0;
	if (storage == NULL)
		return (NULL);
	i = ft_strlen(storage);
	while (storage[i + j] != '\0')
		j++;
	remnant_string = (char *)malloc(sizeof(char) * (j + 1));
	if (!remnant_string)
		return (0);
	j = 0;
	while (storage[i + j] != '\0')
	{
		remnant_string[j] = storage[i + j];
		j++;
	}
	remnant_string[j] = '\0';
	free(storage);
	return (remnant_string);
}
/*
int	main(int argc, char *argv[])
{
		int		file;
		char	*str;

		file = open(argv[1], O_RDONLY);
		if (file == -1)
		{
			printf("ERROR IN OPENING THE FILE");
			return (0);
		}
		str = get_next_line(file);
		while (str)
		{
			printf("%s", str);
			free (str);
			str = get_next_line(file);
		}
		if (!str)
				printf("NULL");
		free (str);
		close (file);
		return (0);
}
*/