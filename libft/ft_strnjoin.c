/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:01 by feedme            #+#    #+#             */
/*   Updated: 2018/12/06 14:29:24 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char			*fusion;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((fusion = (char *)malloc(n + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (i < (unsigned int)n)
	{
		fusion[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		fusion[i + j] = s2[j];
		j++;
	}
	fusion[i + j] = '\0';
	return (fusion);
}
