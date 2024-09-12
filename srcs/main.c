/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:18:11 by phautena          #+#    #+#             */
/*   Updated: 2024/09/12 13:52:21 by phautena         ###   ########.fr       */
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
	if (argc == 1)
		return (0);
	if (head_a == NULL)
		return (printf("Error\n"));
	if (check(&head_a) == false)
	{
		if (get_size(&head_a) == 2)
			sa(&head_a);
		else if (get_size(&head_a) == 3)
			three_sort(&head_a);
		else if (get_size(&head_a) == 4 || get_size(&head_a) == 5)
			four_or_five(&head_a, &head_b);
		else
			radix_sort(&head_a, &head_b);
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
