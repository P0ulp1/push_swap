/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:41:14 by p0ulp1            #+#    #+#             */
/*   Updated: 2024/07/22 10:28:45 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_sort(t_node **head_a, t_node **head_b)
{
	int		max_nbr;
	int		max_bits;
	int		stack_size_a;
	int		i;

	max_nbr = find_biggest(head_a)->data; //Get max number
	max_bits = 0;
	while (max_nbr >> max_bits != 0) //Get max number of pass needed to sort every digit
		max_bits++;
	i = 0;
	while (i < max_bits) //LSD to MSD, i is the current digit
	{
		stack_size_a = get_size(head_a);
		while (stack_size_a-- != 0)
		{
			if ((((*head_a)->data >> i)&1) == 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		while (get_size(head_b) != 0)
			pa(head_a, head_b);
		i++;
	}
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

void	three_sort(t_node **head_a)
{
	t_node	*biggest;

	biggest = find_biggest(head_a);
	if (*head_a == biggest)
		ra(head_a);
	else if ((*head_a)->next == biggest)
		rra(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
		sa(head_a);
}
