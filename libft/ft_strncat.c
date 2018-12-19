/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:49:45 by feedme            #+#    #+#             */
/*   Updated: 2018/04/25 21:42:11 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		pos;

	pos = 0;
	i = 0;
	while (s1[pos])
		pos++;
	while (i < n && s2[i])
	{
		s1[pos] = s2[i];
		i++;
		pos++;
	}
	s1[pos] = '\0';
	return (s1);
}
