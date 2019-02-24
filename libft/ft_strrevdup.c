/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:21:10 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/15 16:21:48 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrevdup(const char *str)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (!(new = ft_strnew(i)))
		return (NULL);
	while (str[--i])
	{
		new[j] = str[i];
		j++;
	}
	new[j] = '\0';
	return (new);
}
