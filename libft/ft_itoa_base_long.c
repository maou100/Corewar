/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:57:00 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/15 12:57:00 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_long(intmax_t value, int base, const char *basetab)
{
	intmax_t	nbr;
	size_t		size;
	char		*str;

	nbr = value;
	size = 1;
	while ((nbr /= base) > 0)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	nbr = value;
	str = (str + size);
	*--str = basetab[nbr % base];
	while ((nbr /= base) > 0)
		*--str = basetab[nbr % base];
	return (str);
}
