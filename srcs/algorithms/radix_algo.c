/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:41:14 by p0ulp1            #+#    #+#             */
/*   Updated: 2024/09/04 15:13:28 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_sort(t_node **head_a, t_node **head_b)
{
	int		max_nbr;
	int		max_bits;
	int		stack_size_a;
	int		i;

	replace_values(head_a);
	max_nbr = find_biggest(head_a)->data;
	max_bits = 0;
	while (max_nbr >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		stack_size_a = get_size(head_a);
		while (stack_size_a-- != 0)
		{
			if ((((*head_a)->data >> i) & 1) == 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		while (get_size(head_b) != 0)
			pa(head_a, head_b);
		i++;
	}
}

t_node	*find_lowest_replace(t_node **head)
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
		temp = find_lowest_replace(head);
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

void	five_sort(t_node **head_a, t_node **head_b)
{
	replace_values(head_a);
	while ((*head_a)->data != 3 && (*head_a)->data != 4)
		ra(head_a);
	pb(head_a, head_b);
	while ((*head_a)->data != 3 && (*head_a)->data != 4)
		ra(head_a);
	pb(head_a, head_b);
	three_sort(head_a);
	if ((*head_b)->data == 3)
		sb(head_b);
	pa(head_a, head_b);
	pa(head_a, head_b);
	while (check(head_a) != true)
		ra(head_a);
}
