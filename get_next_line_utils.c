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
	else
		return (1);
}

/*returning pointer to the last note in storage*/
t_list	*ft_lst_get_last(t_list *storage)
{
	t_list	*current;

	current = storage;
	while (storage && current->next)
	{
		current = current->next;
	}
	return (current);
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
		while (storage->contetn[i])
		{
			if (storage->content[i] == '\n')
			{
				len++;
				break;
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