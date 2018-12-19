/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:32:38 by feedme            #+#    #+#             */
/*   Updated: 2018/04/23 13:51:37 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memzone;

	memzone = (void *)malloc(sizeof(void *) * size);
	if (memzone == NULL)
		return (NULL);
	ft_bzero(memzone, size);
	return (memzone);
}
