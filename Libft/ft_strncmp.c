/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:22:28 by phautena          #+#    #+#             */
/*   Updated: 2024/06/28 10:47:58 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	unsigned char		*s1_temp;
	unsigned char		*s2_temp;
	size_t				i;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	i = 0;
	while (s1_temp[i] != '\0' && s2_temp[i] != '\0')
	{
		if (s1_temp[i] == '-' || s1_temp[i] == '+'
			|| s2_temp[i] == '-' || s2_temp[i] == '+')
			i++;
		if (s1_temp[i] != s2_temp[i] || s1_temp[i] == '\0'
			|| s2_temp[i] == '\0')
		{
			return (s1_temp[i] - s2_temp[i]);
		}
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}
