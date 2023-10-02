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
t_list *ft_lst_get_last(t_list *storage)
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
		
	}
}
