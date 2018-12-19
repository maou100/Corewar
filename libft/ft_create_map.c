/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:21:53 by feedme            #+#    #+#             */
/*   Updated: 2018/10/23 23:09:42 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_map(int line_c, int col_c, char c)
{
	char	**map;
	int		j;
	int		i;

	j = -1;
	IF_NULL((map = (char**)malloc(sizeof(char*) * (line_c + 1))), NULL);
	map[line_c] = NULL;
	while (++j < line_c)
	{
		i = -1;
		IF_NULL((map[j] = (char*)malloc(col_c + 1)), NULL);
		while (++i < col_c)
			map[j][i] = c;
		map[j][i] = '\0';
	}
	return (map);
}
