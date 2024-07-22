/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:55 by p0ulp1            #+#    #+#             */
/*   Updated: 2024/07/22 12:37:46 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*target_b(t_node **head_a, t_node **head_b)
{
	t_node	*temp;
	t_node	*target;

	temp = *head_a;
	target = NULL;
	while (temp != NULL)
	{
		if (temp->data == (*head_b)->data + 1)
		{
			target = temp;
			return (target);
		}
		temp = temp->next;
	}
	target = find_lowest(head_a);
	return (target);
}

t_node	*find_lowest(t_node **head)
{
	t_node	*temp;
	t_node	*lowest;
	int		low_value;

	temp = *head;
	lowest = NULL;
	low_value = INT_MAX;
	if (*head != NULL)
	{
		while (temp != NULL)
		{
			if (temp->data < low_value)
			{
				low_value = temp->data;
				lowest = temp;
			}
			temp = temp->next;
		}
	}
	return (lowest);
}