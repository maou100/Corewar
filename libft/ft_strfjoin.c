/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:40:16 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/12 14:40:17 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew((int)ft_strlen(s1) + (int)ft_strlen(s2));
	while (s1[i])
		new[j++] = s1[i++];
	ft_strdel(&s1);
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	ft_strdel(&s2);
	return (new);
}
