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
	char		*new_string;
	int			gelesen;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gelesen = 1;
	new_string = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!new_string)
		return (free(storage), NULL);
	while (ft_newline(storage) == 0 && gelesen != 0)
	{
		gelesen = read(fd, new_string, BUFFER_SIZE);
		if (gelesen == -1)
			return (free(new_string), free(storage), storage = NULL, NULL);
		new_string[gelesen] = '\0';
		storage = ft_strjoin(storage, new_string);
		if (storage == NULL)
			return (NULL);
	}
	free(new_string);
	new_string = ft_storage_to_output(storage);
	storage = ft_extract_remnant(storage);
	return (new_string);
}

char	*ft_storage_to_output(char *storage)
{
	int		i;
	char	*output;

	if (!storage || !storage[0])
		return (NULL);
	i = ft_strlen(storage, '\n');
	if (storage[i] == '\n')
		i++;
	output = (char *)malloc(1 + i * sizeof(char));
	if (!output)
		return (free(storage), NULL);
	i = ft_strcpy(output, storage, '\n', 0);
	if (storage[i] == '\n')
		output[i++] = '\n';
	output[i] = '\0';
	return (output);
}

char	*ft_extract_remnant(char *storage)
{
	char	*remnant;
	int		start;
	int		end;

	start = ft_strlen(storage, '\n');
	if (storage[start] == '\0')
	{
		free(storage);
		return (NULL);
	}
	if (storage[start] == '\n')
		start++;
	end = ft_strlen(storage, '\0');
	remnant = (char *)malloc(1 + end - start);
	if (!remnant)
		return (free(storage), NULL);
	end = ft_strcpy(remnant, storage, '\0', start);
	remnant[end] = '\0';
	free(storage);
	return (remnant);
}

int	main(int argc, char *argv[])
{
	int		file;
	char	*str;

	if (argc == 0)
		return (0);
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
