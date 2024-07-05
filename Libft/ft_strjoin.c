/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:37:29 by phautena          #+#    #+#             */
/*   Updated: 2024/06/28 10:43:30 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	string = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		string[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		string[s1_len + i] = s2[i];
		i++;
	}
	string[s1_len + s2_len] = '\0';
	return (string);
}
