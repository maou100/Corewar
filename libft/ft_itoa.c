/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:23:47 by feedme            #+#    #+#             */
/*   Updated: 2018/05/05 00:48:22 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_spacecount(int n)
{
	unsigned int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char			*ft_min_int(void)
{
	char			*str;

	str = (char *)malloc(12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char				*ft_itoa(int n)
{
	FELIX;
	if (n == -2147483648)
		return (ft_min_int());
	if ((str = (char *)malloc(ft_spacecount(n) + 1)) == NULL)
		return (NULL);
	str[ft_spacecount(n)] = '\0';
	if (n <= 0)
	{
		if (n == 0)
		{
			str[0] = '0';
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}
