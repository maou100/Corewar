/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:15:18 by amagnan           #+#    #+#             */
/*   Updated: 2018/11/05 13:15:18 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_mapalloc(int i, int j)
{
	char		**map;
	int			k;

	k = 0;
	if (!(map = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	while (k < i)
	{
		map[k] = ft_strnew(j);
		k++;
	}
	map[k] = NULL;
	return (map);
}
