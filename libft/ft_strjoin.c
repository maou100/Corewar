/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:01:36 by amagnan           #+#    #+#             */
/*   Updated: 2018/09/11 14:01:37 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!tmp)
		return (NULL);
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strcat(tmp, s2);
	return (tmp);
}
