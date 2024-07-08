/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:28:26 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 14:00:41 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_size(t_node **head)
{
	t_node	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	del_first(t_node **head)
{
	t_node	*temp;

	if (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
