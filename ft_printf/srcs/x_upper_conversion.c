/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_upper_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:33:02 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:09:11 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_upper_conversion(unsigned int n, int *count_ptr)
{
	char	*table;

	table = "0123456789ABCDEF";
	if (n > 15)
	{
		x_upper_conversion(n / 16, count_ptr);
		x_upper_conversion(n % 16, count_ptr);
	}
	else
	{
		write(1, &table[n], 1);
		*count_ptr += 1;
	}
}
