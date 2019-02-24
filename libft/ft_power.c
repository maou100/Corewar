/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:26:28 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/10 23:26:31 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int ft_power(int n, int pow)
{
	int		i;
	unsigned long int		nb;

	nb = n;
	i = 1;
	if (!pow)
		return (1);
	while (i < pow)
	{
		nb *= n;
		i++;
	}
	return (nb);
}
