/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:50:23 by phautena          #+#    #+#             */
/*   Updated: 2024/07/10 12:37:49 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_sort(t_node **head_a)
{
	t_node	*biggest;

	biggest = get_biggest(head_a);
	if (*head_a == biggest)
		ra(head_a);
	else if ((*head_a)->next == biggest)
		rra(head_a);
	if ((*head_a)->data > (*head_a)->next->data)
		sa(head_a);
}

