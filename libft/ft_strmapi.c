/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:29:31 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 13:29:32 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	i;

	if (!s || !f)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (tmp)
	{
		while (s[i])
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
