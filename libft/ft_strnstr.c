/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:07:58 by feedme            #+#    #+#             */
/*   Updated: 2018/04/26 15:39:40 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (haystack[i] == needle[i] && haystack[i] == '\0')
		return ((char *)&haystack[i]);
	while (haystack[i] && i <= len)
	{
		j = i;
		while (haystack[j] == needle[j - i] && haystack[j] && j < len)
			j++;
		if (needle[j - i] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
