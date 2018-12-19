/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:42:02 by feedme            #+#    #+#             */
/*   Updated: 2018/05/05 18:13:40 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (s[i] != c && i != -1)
		i--;
	if (i == -1)
		return (NULL);
	else
		return ((char *)s + i);
}
