/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:05:38 by feedme            #+#    #+#             */
/*   Updated: 2018/05/05 18:34:22 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char*)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((unsigned char *)tmp + i);
		i++;
	}
	return (NULL);
}
