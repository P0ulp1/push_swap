/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:34:20 by phautena          #+#    #+#             */
/*   Updated: 2024/07/18 14:44:41 by p0ulp1           ###   ########.fr       */
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