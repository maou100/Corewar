/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:31:42 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 15:31:44 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_calculate(int n)
{
	int			count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char		*ft_return(int n)
{
	int			size;
	char		*str;

	size = 11;
	if (n == 0)
		size = 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	else
	{
		str[size--] = '8';
		str[0] = '-';
		n = (n / 10) * -1;
		while (n > 0)
		{
			str[size] = n % 10 + '0';
			n = n / 10;
			size--;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			size;
	char		*str;

	size = ft_calculate(n);
	if (n == -2147483648 || n == 0)
		return (ft_return(n));
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[size] = '\0';
	size--;
	while (n > 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
