/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:06:08 by p0ulp1            #+#    #+#             */
/*   Updated: 2024/07/16 11:39:13 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			if (temp->data < low_value && temp->is_replaced == 0)
			{
				low_value = temp->data;
				lowest = temp;
			}
			temp = temp->next;
		}
	}
	return (lowest);
}

void	replace_values(t_node **head)
{
	int		size;
	int		i;
	t_node	*temp;

	size = get_size(head);
	i = 0;
	while (size != 0)
	{
		temp = find_lowest(head);
		temp->data = i;
		temp->is_replaced = 1;
		i++;
		size--;
	}
}
