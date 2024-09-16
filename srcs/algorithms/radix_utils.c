/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:55 by p0ulp1            #+#    #+#             */
/*   Updated: 2024/09/16 14:10:02 by phautena         ###   ########.fr       */
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

void	four_or_five(t_node **head_a, t_node **head_b)
{
	if (get_size(head_a) == 4)
		four_sort(head_a, head_b);
	else if (get_size(head_a) == 5)
		five_sort(head_a, head_b);
}

void	four_sort(t_node **head_a, t_node **head_b)
{
	replace_values(head_a);
	while ((*head_a)->data != 3)
		ra(head_a);
	pb(head_a, head_b);
	three_sort(head_a);
	pa(head_a, head_b);
	while (check(head_a) != true)
		ra(head_a);
}
