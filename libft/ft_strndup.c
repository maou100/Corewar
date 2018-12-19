/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:16:19 by feedme            #+#    #+#             */
/*   Updated: 2018/08/27 18:22:31 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	char	*dst;
	int		i;

	i = -1;
	if (!(dst = (char*)ft_strnew(n)))
		return (NULL);
	while (++i < n)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
