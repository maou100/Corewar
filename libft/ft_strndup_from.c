/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_from.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 20:18:41 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/18 20:18:44 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup_from(char *str, int a, int b)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[a] && a <= b)
	{
		new[i] = str[a];
		i++;
		a++;
	}
	new[i] = '\0';
	return (new);
}
