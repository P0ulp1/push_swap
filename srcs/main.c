/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:18:11 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:37:37 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node		*head_a;
	t_node		*head_b;

	head_a = NULL;
	head_b = NULL;
	ultimate_parser(argc, argv, &head_a);
	if (head_a == NULL)
		return (printf("Error\n"));
	if (check(&head_a) == false)
	{
		if (get_size(&head_a) == 2)
			sa(&head_a);
		else if (get_size(&head_a) == 3)
			three_sort(&head_a);
		else
		{
			//big_sort(&head_a, &head_b);
			print_linked_list(&head_a);
			replace_values(&head_a);
			print_linked_list(&head_a);
			(void)head_b;
		}
	}
	else
		printf("Already Sorted\n");
	ft_free(&head_a);
	return (0);
}

void	ft_free(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	free_array(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}