/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_left_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:09:40 by feedme            #+#    #+#             */
/*   Updated: 2018/10/18 23:31:59 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_left_ext(char *str, int extension)
{
	char	*tmp;
	int		i;
	int		len;

	len = ft_strlen(str) + extension;
	i = 0;
	IF_NULL((tmp = ft_strnew(len)), NULL);
	ft_bzero(tmp, len);
	while ((extension + i) < len)
	{
		tmp[extension + i] = str[i];
		i++;
	}
	return (tmp);
}
