/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:58 by phautena          #+#    #+#             */
/*   Updated: 2024/09/17 15:36:14 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ultimate_parser(int argc, char *argv[], t_node **head)
{
	if (argc > 2)
		multiple_args(argc, argv, head, 0);
	else if (argc == 2)
		array_parsing(argv[1], head);
}

void	multiple_args(int argc, char *argv[], t_node **head, int was_string)
{
	int		count;

	if (was_string == 0)
		count = 1;
	else
		count = 0;
	while (count < argc)
	{
		if (is_number(argv[count]) == true)
		{
			add_to_end(ft_atoi(argv[count]), head);
			count++;
		}
		else
		{
			ft_free(head);
			*head = NULL;
			return ;
		}
	}
	if (duplicate_check(head) == 1)
	{
		ft_free(head);
		*head = NULL;
		return ;
	}
}

void	array_parsing(char *array, t_node **head)
{
	char	**array_splitted;
	int		i;

	if (is_valid(array) == true)
	{
		array_splitted = ft_split(array, ' ');
		i = 0;
		while (array_splitted[i] != NULL)
			i++;
		multiple_args(i, array_splitted, head, 1);
		if (array_splitted != NULL)
			free_array(array_splitted);
	}
	else
		*head = NULL;
}

bool	is_number(char *number)
{
	int	i;

	i = 0;
	if (ft_atoi(number) <= INT_MIN || ft_atoi(number) >= INT_MAX)
		return (false);
	else if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] != '\0')
	{
		if (ft_isdigit(number[i]) == 0)
			i++;
		else
			return (false);
	}
	return (true);
}

bool	is_valid(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == ' ' && ft_isdigit(array[i + 1]) == 1
			&& array[i + 1] != '+' && array[i + 1] != '-')
			return (false);
		else if ((array[i] == '+' || array[i] == '-')
			&& ft_isdigit(array[i + 1]) == 1)
			return (false);
		i++;
	}
	return (true);
}
