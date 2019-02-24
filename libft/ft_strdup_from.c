/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:41:35 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/19 13:41:36 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup_from(char *str, int a)
{
	char		*new;
	int			i;

	i = 0;
	new = ft_strnew(ft_strlen(str) - a + 1);
	while (str[a])
	{
		new[i] = str[a];
		a++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
