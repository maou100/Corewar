/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:02:51 by feedme            #+#    #+#             */
/*   Updated: 2018/06/06 22:52:24 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array)
{
	char			**cpy;
	unsigned int	i;

	i = 0;
	cpy = &array[i];
	while (array[i])
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
