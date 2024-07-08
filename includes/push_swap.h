/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:29:14 by phautena          #+#    #+#             */
/*   Updated: 2024/07/08 13:59:54 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	add_to_empty(int data, t_node **head);
void	add_to_beg(int data, t_node **head);
void	add_to_end(int data, t_node **head);
//t_node	*del_first(t_node *tail);
//t_node	*del_last(t_node *tail);

void	ultimate_parser(int argc, char *argv[], t_node **head);
void	multiple_args(int argc, char *argv[], t_node **head, int was_string);
void	array_parsing(char *array, t_node **head);

bool	is_number(char *number);
bool	is_valid(char *array);
void	print_linked_list(t_node *tail);
int		duplicate_check(t_node **head);
int		get_size(t_node **head);
void	del_first(t_node **head);

void	swap(t_node **head);
void	sa(t_node **head_a);
void	sb(t_node **head_b);
void	ss(t_node **head_a, t_node **head_b);
void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);

#endif
