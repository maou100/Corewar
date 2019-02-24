/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:53:58 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 12:53:59 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
