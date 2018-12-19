/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:56:14 by feedme            #+#    #+#             */
/*   Updated: 2018/10/17 18:03:15 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	char	*new;
	int		i;

	i = -1;
	len = ft_strlen(str);
	if (!(new = (char*)malloc(len + 1)))
		ft_exit_msg("malloc failed\n");
	while (--len >= 0)
		new[++i] = str[len];
	new[++i] = '\0';
	free(str);
	return (new);
}
