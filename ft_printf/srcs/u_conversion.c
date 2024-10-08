/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:14:06 by phautena          #+#    #+#             */
/*   Updated: 2024/07/16 11:09:24 by p0ulp1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u_conversion(unsigned int n, int *count_ptr)
{
	int	n2c;

	if (n > 9)
	{
		u_conversion(n / 10, count_ptr);
		u_conversion(n % 10, count_ptr);
	}
	else
	{
		n2c = n + '0';
		write(1, &n2c, 1);
		*count_ptr += 1;
	}
}
