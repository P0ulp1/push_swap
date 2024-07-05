/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:47:12 by phautena          #+#    #+#             */
/*   Updated: 2024/06/10 14:15:56 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_conversion(unsigned int n, int *count_ptr)
{
	char	*table;

	table = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		*count_ptr += 1;
		n *= -1;
		x_conversion(n, count_ptr);
	}
	else if (n > 15)
	{
		x_conversion(n / 16, count_ptr);
		x_conversion(n % 16, count_ptr);
	}
	else
	{
		write(1, &table[n], 1);
		*count_ptr += 1;
	}
}
