/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:29:00 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 14:51:11 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_node **head)
{
	t_node	*node;
	int		temp;

	node = *head;
	temp = node->data;
	while (node->next != NULL)
	{
		node->data = node->next->data;
		node = node->next;
	}
	node->data = temp;
}

void	ra(t_node **head_a)
{
	rotate(head_a);
	ft_printf("ra\n");
}

void	rb(t_node **head_b)
{
	rotate(head_b);
	ft_printf("rb\n");
}

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a);
	rb(head_b);
}
