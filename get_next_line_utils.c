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
int	newline(t_list *storage)
{
	int		i;
	t_list	*position;

	if (storage == NULL)
		return (0);
	position = storage;
	//traversing list to last node
	while (position->next != NULL)
	{
		position = position->next;
	}
	i = 0;
	while (position->content[i])
	{
		if (position->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *src, char *dest, int gelesen)
{
	int	i;

	i = 0;
	while (src[i] && i < gelesen)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/*calculating number of char in current line
includig \n if there is one, allocating memory*/
int	count_length(t_list *storage)
{
	int	i;
	int	length;

	length = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			if (storage->content[i] == '\n')
			{
				length++;
				break ;
			}
			length++;
			i++;
		}
		storage = storage->next;
	}
	return (length);
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
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*returning pointer to the last node in storage*/
// t_list	*retrieve_last_node(t_list *storage)
// {
// 	t_list	*temporary_ptr;

// 	*temporary_ptr = *storage;
// 	while (temporary_ptr->next != NULL)
// 		temporary_ptr = temporary_ptr->next;
// 	return (temporary_ptr);
// }
