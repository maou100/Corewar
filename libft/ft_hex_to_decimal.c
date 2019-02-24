/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:17:45 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/10 23:17:46 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int		ft_hex_to_decimal(char *number)
{
	int			i;
	int			j;
	unsigned long int			n;
	int			add;

	n = 0;
	j = 0;
	i = (int)(ft_strlen(number) - 1);
	while (i > -1)
	{
		if (ft_isdigit(number[i]))
			add = number[i] - '0';
		else if (number[i] >= 65 && number[i] <= 70)
			add = number[i] - 55;
		else if (number[i] >= 97 && number[i] <= 102)
			add = number[i] - 87;
		n = n + (add * ft_power(16, j));
		j++;
		i--;
	}
	return (n);
}
