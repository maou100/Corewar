/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:19:51 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 16:19:52 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hay, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*n)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (i + j < len && hay[i + j] == n[j] && n[j] != '\0')
			j++;
		if (n[j] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
