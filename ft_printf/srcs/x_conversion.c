/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:47:12 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:08:41 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_conversion(unsigned int n, int *count_ptr)
{
	char	*table;

	table = "0123456789abcdef";
	if (n > 15)
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
