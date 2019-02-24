/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:23:12 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 13:23:14 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
