/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:15:18 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 16:15:19 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;
	size_t	i;

	i = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (string1[i] == string2[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
