/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:18:11 by phautena          #+#    #+#             */
/*   Updated: 2024/07/02 15:38:39 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node 		*tail_a;
	t_node		*tail_b;

	tail_a = NULL;
	tail_b = NULL;
	tail_a = ultimate_parser(argc, argv, tail_a);
	if (tail_a != NULL)
	{
		if (duplicate_check(tail_a) == 1)
			tail_a = NULL;
	}
	if (tail_a == NULL)
		return (printf("Error\n"));
	print_linked_list(tail_a);
	return (0);
}