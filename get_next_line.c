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

char	*ft_storage_to_output(char *storage)
{
	int		i;
	char	*output;

	if (!storage || !storage[0])
		return (NULL);
	i = ft_inclusive_strlen(storage);
	output = (char *)malloc(1 + i * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
	{
		output[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		output[i] = '\n';
	output[++i] = '\0';
	return (output);
}

char	*ft_move_start(char	*start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*ouput;
	int			fd_read;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	ouput = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!ouput)
		return (NULL);
	while (ft_newline(storage) == 0 && fd_read != 0)
	{
		fd_read = read(fd, ouput, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(ouput);
			return (NULL);
		}
		ouput[fd_read] = '\0';
		storage = ft_strjoin(storage, ouput);
	}
	free(ouput);
	ouput = ft_storage_to_output(storage);
	storage = ft_move_start(storage);
	return (ouput);
}


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
