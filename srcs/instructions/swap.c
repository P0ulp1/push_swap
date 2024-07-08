/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:30:08 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 14:00:56 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_node **head)
{
	t_node	*temp;

	if (get_size(head) >= 2)
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		(*head)->prev = temp;
		temp->next = (*head);
		temp->prev = NULL;
		*head = temp;
	}
}

void	sa(t_node **head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	sb(t_node **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_node **head_a, t_node **head_b)
{
	sa(head_a);
	sb(head_b);
}
