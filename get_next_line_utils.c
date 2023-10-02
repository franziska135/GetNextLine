/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:26:43 by fmarggra          #+#    #+#             */
/*   Updated: 2023/09/29 11:26:45 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*looking for \n in linked list*/
int	ft_newline(t_list *storage)
{
	int		i;
	t_list	*position;

	if (storage == NULL)
		return (0);
	position = ft_lst_get_last(storage);
	i = 0;
	while (position->content[i])
	{
		if (position->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*returning pointer to the last note in storage*/
t_list	*retreive_last_node(t_list *storage)
{
	t_list	*temporary_ptr;

	*temporary_ptr = *storage;
	while (temporary_ptr->next != NULL)
		temporary_ptr = temporary_ptr->next;
	return (temporary_ptr);
}

/*calculating number of char in current line
includig \n if there is one, allocating memory*/
void	generate_line(char **line, t_list *storage)
{
	int	i;
	int	len;

	len = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			if (storage->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		storage = storage->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/*free storage*/
void	free_storage(t_list *storage)
{
	t_list	*position;
	t_list	*next;

	position = storage;
	{
		free(position->content);
		next = position->next;
		free(position);
		position = next;
	}
}

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}