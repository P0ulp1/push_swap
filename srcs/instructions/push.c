/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:24 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 13:55:27 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	int	temp;

	if (get_size(head_b) > 0)
	{
		temp = (*head_b)->data;
		del_first(head_b);
		add_to_beg(temp, head_a);
	}
}

void	pb(t_node **head_a, t_node **head_b)
{
	int	temp;

	if (get_size(head_a) > 0)
	{
		temp = (*head_a)->data;
		del_first(head_a);
		add_to_beg(temp, head_b);
	}
}
