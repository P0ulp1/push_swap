/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:28:26 by phautena          #+#    #+#             */
/*   Updated: 2024/08/16 10:28:44 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_size(t_node **head)
{
	t_node	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	del_first(t_node **head)
{
	t_node	*temp;

	if (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

long	data_pos(t_node **head, int pos)
{
	t_node	*temp;

	if (*head != NULL)
	{
		temp = *head;
		while (pos > 1)
		{
			temp = temp->next;
			pos--;
			if (temp->next == NULL)
				return (temp->data);
		}
		return (temp->data);
	}
	return (1);
}

t_node	*find_biggest(t_node **head)
{
	t_node	*temp;
	t_node	*biggest;

	temp = *head;
	biggest = *head;
	while (temp != NULL)
	{
		if (temp->data > biggest->data)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

bool	check(t_node **head_a)
{
	t_node	*node;

	node = *head_a;
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}
