/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:42:14 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 14:57:22 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	int		temp;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	temp = last->data;
	while (last != *head)
	{
		last->data = last->prev->data;
		last = last->prev;
	}
	(*head)->data = temp;
}

void	rra(t_node **head_a)
{
	reverse_rotate(head_a);
	ft_printf("rra\n");
}

void	rrb(t_node **head_b)
{
	reverse_rotate(head_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **head_a, t_node **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_printf("rrr\n");
}
