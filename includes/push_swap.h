/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:29:14 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:38:32 by p0ulp1           ###   ########.fr       */
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
	int				is_replaced;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	add_to_empty(int data, t_node **head);
void	add_to_beg(int data, t_node **head);
void	add_to_end(int data, t_node **head);

void	ultimate_parser(int argc, char *argv[], t_node **head);
void	multiple_args(int argc, char *argv[], t_node **head, int was_string);
void	array_parsing(char *array, t_node **head);

bool	is_number(char *number);
bool	is_valid(char *array);
void	print_linked_list(t_node **head);
int		duplicate_check(t_node **head);
int		get_size(t_node **head);
void	del_first(t_node **head);
bool	check(t_node **head_a);
long	data_pos(t_node **head, int pos);
t_node	*get_biggest(t_node **head);

void	swap(t_node **head);
void	sa(t_node **head_a);
void	sb(t_node **head_b);
void	ss(t_node **head_a, t_node **head_b);

void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);

void	rotate(t_node **head);
void	ra(t_node **head_a);
void	rb(t_node **head_b);
void	rr(t_node **head_a, t_node **head_b);

void	reverse_rotate(t_node **head);
void	rra(t_node **head_a);
void	rrb(t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);

void	three_sort(t_node **head_a);
void	big_sort(t_node **head_a, t_node **head_b);

void	set_index(t_node **head);

void	ft_free(t_node **head);
void	free_array(char *argv[]);

t_node	*find_lowest(t_node **head);
void	replace_values(t_node **head);

#endif
