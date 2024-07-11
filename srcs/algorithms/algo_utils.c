/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:20 by phautena          #+#    #+#             */
/*   Updated: 2024/07/10 14:44:13 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	set_index(t_node **head)
{
	t_node	*temp;
	int		i;
	int		stack_size;

	temp = *head;
	i = 0;
	stack_size = get_size(head);
	while (i < stack_size)
	{
		temp->index = i;
		if (i >= stack_size / 2)
			temp->median = true;
		else
			temp->median = false;
		i++;
		temp = temp->next;
	}
}

void	set_target(t_node **head_a, t_node **head_b)
{
	t_node	*target_node;
	t_node	*temp_a;
	t_node	*temp_b;
	long	closest_big;

	temp_b = *head_b;
	while (temp_b != NULL)
	{
		temp_a = *head_a;
		closest_big = LONG_MAX;
		while (temp_a != NULL)
		{
			if (temp_a->data > temp_b->data && temp_a->data < closest_big)
			{
				closest_big = temp_a->data;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (closest_big == LONG_MAX)
			temp_b = //smallest
		
	}
}