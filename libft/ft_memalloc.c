/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:44:05 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 12:44:06 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
