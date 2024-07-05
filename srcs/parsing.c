/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:58 by phautena          #+#    #+#             */
/*   Updated: 2024/07/02 15:03:19 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ultimate_parser(int argc, char *argv[], t_node *tail)
{
	if (argc > 2)
		tail = multiple_args_parsing(argc, argv, tail, 0);
	else if (argc == 2)
		tail = array_parsing(argv[1], tail);
	return (tail);
}

t_node	*multiple_args_parsing(int argc, char *argv[], t_node *tail, int was_string)
{
	int		count;

	if (was_string == 0)
		count = 1;
	else
		count = 0;
	while (count < argc)
	{
		if (isNumber(argv[count]) == true)
		{
			tail = add_to_end(tail, ft_atoi(argv[count]));
			count++;
		}
		else
		{
			tail = NULL;
			return (tail);
		}
	}
	return (tail);
}

t_node	*array_parsing(char *array, t_node *tail)
{
	char	**array_splitted;
	int		i;
	
	if (isValid(array) == true)
	{
		array_splitted = ft_split(array, ' ');
		i = 0;
		while (array_splitted[i] != NULL)
			i++;
		tail = multiple_args_parsing(i, array_splitted, tail, 1);
		return (tail);
	}
	else
	{
		tail = NULL;
		return (tail);
	}
}

bool	isNumber(char *number)
{
	int	i;

	i = 0;
	if (ft_atoi(number) < INT_MIN || ft_atoi(number) > INT_MAX)
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

bool	isValid(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == ' ' && ft_isdigit(array[i + 1]) == 1 && array[i + 1] != '+' && array[i + 1] != '-')
			return (false);
		else if ((array[i] == '+' || array[i] == '-') && ft_isdigit(array[i + 1]) == 1)
			return (false);
		i++;
	}
	return (true);
}