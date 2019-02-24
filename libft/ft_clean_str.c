/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 04:43:46 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/20 04:43:47 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_clean_str(char *str)
{
	char			*new_str;

	new_str = ft_strnew(ft_strlen(str));
	new_str = ft_strcpy(new_str, str);
	ft_strdel(&str);
	return (new_str);
}
