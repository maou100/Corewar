/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:15:50 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 16:15:51 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	cur = (unsigned char *)b;
	while (i < len)
	{
		cur[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
