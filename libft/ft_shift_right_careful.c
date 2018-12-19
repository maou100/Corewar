/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_right_careful.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:16:58 by feedme            #+#    #+#             */
/*   Updated: 2018/10/23 23:08:28 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** !WARNING!
**
** This function needs to be used with caution, in other
** words you need to be certain
** that your string has enough malloced space to do a right shift,
** so be careful with
** your dist value, be certain about its value.
*/

char		*ft_shift_right_careful(char *str, int dist)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (--i >= 0)
		str[i + dist] = str[i];
	while (++i < dist)
		str[i] = ' ';
	return (str);
}
