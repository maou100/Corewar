/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:51:20 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 13:51:22 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	int		x;

	i = 0;
	x = start;
	if (!s)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (s[x] && i < len)
	{
		tmp[i] = s[x];
		i++;
		x++;
	}
	tmp[i] = '\0';
	return (tmp);
}
