/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:05:09 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/19 12:05:09 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcpy_from_to(char *str, int a, int b)
{
	char		*new;
	int			i;

	i = 0;
	new = ft_strnew(b - a + 1);
	while (a <= b)
	{
		new[i] = str[a];
		a++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
