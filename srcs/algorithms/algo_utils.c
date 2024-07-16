/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:20 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:09:50 by p0ulp1           ###   ########.fr       */
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
