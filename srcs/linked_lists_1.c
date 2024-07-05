/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:55:40 by phautena          #+#    #+#             */
/*   Updated: 2024/07/02 15:00:53 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*add_to_empty(int data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->prev = temp;
	temp->next = temp;
	temp->data = data;
	return (temp);
}

t_node	*add_to_beg(t_node *tail, int data)
{
	t_node	*new_ptr;
	t_node	*temp;

	new_ptr = add_to_empty(data);
	if (tail == NULL)
		return (new_ptr);
	else
	{
		temp = tail->next;
		new_ptr->next = temp;
		new_ptr->prev = tail;
		tail->next = new_ptr;
		temp->prev = new_ptr;
		return (tail);
	}
}

t_node	*add_to_end(t_node *tail, int data)
{
	t_node	*new_ptr;
	t_node	*temp;

	new_ptr = add_to_empty(data);
	if (tail == NULL)
		return (new_ptr);
	else
	{
		temp = tail->next;
		new_ptr->next = temp;
		new_ptr->prev = tail;
		tail->next = new_ptr;
		temp->prev = new_ptr;
		tail = new_ptr;
		return (tail);
	}
}
int	duplicate_check(t_node *tail)
{
	t_node	*to_check;
	t_node	*checking;

	to_check = tail->next;
	while (to_check->next != tail->next)
	{
		checking = to_check->next;
		while (checking->next != to_check->next)
		{
			if (to_check->data == checking->data)
				return (1);
			checking = checking->next;
		}
		to_check = to_check->next;
	}
	return (0);
}

// TO REMOVE BEFORE PUSHING
void	print_linked_list(t_node *tail)
{
	t_node	*temp;

	temp = tail->next;
	do
	{
		printf("Value: %d\n", temp->data);
		temp = temp->next;
	} while (temp != tail->next);
}
