/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:43:52 by feedme            #+#    #+#             */
/*   Updated: 2018/10/18 23:30:30 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_shift_left(char *str, int dist)
{
	int		i;
	int		dist_tmp;

	dist_tmp = dist;
	i = -1;
	dist--;
	while (str[++dist])
		str[++i] = str[dist];
	while (--dist_tmp >= 0)
		str[++i] = '\0';
	return (str);
}
