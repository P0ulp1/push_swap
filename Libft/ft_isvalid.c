/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:57:37 by phautena          #+#    #+#             */
/*   Updated: 2024/06/28 11:07:12 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvalid(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == ' ' && ((array[i + 1] < '0'
					|| array[i + 1] > '9') && array[i + 1] != '+'
				&& array[i + 1] != '-'))
			return (-1);
		else if ((array[i] == '+' || array[i] == '-')
			&& ((array[i + 1] < '0' || array[i + 1] > '9')
				&& (array[i + 1] == '+' || array[i + 1] == '-')))
			return (-1);
		else if ((array[i] == '+' || array[i] == '-'
				|| array[i] == ' ') || (array[i] >= '0' && array[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}
