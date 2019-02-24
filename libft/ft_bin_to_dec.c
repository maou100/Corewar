/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:56:49 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/06 17:56:49 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_bin_to_dec(const char *bit)
{
	int		i;
	int		nb;
	int		count;

	count = 1;
	nb = 0;
	i = ft_strlen(bit) - 1;
	while (i >= 0)
	{
		nb += (bit[i] - '0') * count;
		count *= 2;
		i--;
	}
	return (nb);
}
