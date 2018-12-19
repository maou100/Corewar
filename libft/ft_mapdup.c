/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:51:19 by feedme            #+#    #+#             */
/*   Updated: 2018/10/25 00:08:17 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mapdup(char **map)
{
	char	**new;
	int		i;
	int		len1;

	i = -1;
	IF_NULL(map, NULL);
	len1 = 0;
	while (map[len1])
		len1++;
	IF_NULL((new = (char**)malloc(sizeof(char*) * (len1 + 1))), NULL);
	new[len1] = NULL;
	while (++i < len1)
		IF_NULL((new[i] = ft_strdup(map[i])), NULL);
	return (new);
}
