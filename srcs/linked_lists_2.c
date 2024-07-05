/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:16:31 by phautena          #+#    #+#             */
/*   Updated: 2024/07/02 15:25:59 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*del_first(t_node *tail)
{
	t_node	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);
	return (tail);
}

t_node	*del_last(t_node *tail)
{
	t_node	*temp;
	
	if (tail == NULL)
		return (tail);
	temp = tail->prev;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	temp->next = tail->next;
	tail->next->prev = temp;
	free(tail);
	tail = temp;
	return (tail);
}