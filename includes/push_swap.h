/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:29:14 by phautena          #+#    #+#             */
/*   Updated: 2024/07/02 15:26:36 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <stdbool.h>

typedef struct s_node
{
	int	data;
	struct s_node *prev;
	struct s_node *next;
}	t_node;

t_node	*add_to_empty(int data);
t_node	*add_to_beg(t_node *tail, int data);
t_node	*add_to_end(t_node *tail, int data);
t_node	*del_first(t_node *tail);
t_node	*del_last(t_node *tail);

t_node	*ultimate_parser(int argc, char *argv[], t_node *tail);
t_node	*multiple_args_parsing(int argc, char *argv[], t_node *tail, int was_string);
t_node	*array_parsing(char *array, t_node *tail);

bool	isNumber(char *number);
bool	isValid(char *array);
void	print_linked_list(t_node *tail);
int		duplicate_check(t_node *tail);

#endif
