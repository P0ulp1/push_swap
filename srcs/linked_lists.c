/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:55:40 by phautena          #+#    #+#             */
/*   Updated: 2024/07/10 11:42:52 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_to_empty(int data, t_node **head)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	*head = new_node;
}

void	add_to_beg(int data, t_node **head)
{
	t_node	*new_node;

	if (*head == NULL)
		add_to_empty(data, head);
	else
	{
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return ;
		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void	add_to_end(int data, t_node **head)
{
	t_node	*new_node;
	t_node	*temp;

	if (*head == NULL)
		add_to_empty(data, head);
	else
	{
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return ;
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = temp;
		temp->next = new_node;
	}
}

int	duplicate_check(t_node **head)
{
	t_node	*to_check;
	t_node	*checking;

	to_check = *head;
	while (to_check != NULL)
	{
		checking = to_check->next;
		while (checking != NULL)
		{
			if (to_check->data == checking->data)
				return (1);
			checking = checking->next;
		}
		to_check = to_check->next;
	}
	return (0);
}

void	print_linked_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("Value: %d\n", temp->data);
		temp = temp->next;
	}
	ft_printf("\n\n");
}
