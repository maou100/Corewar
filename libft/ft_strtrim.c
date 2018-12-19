/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:48:13 by feedme            #+#    #+#             */
/*   Updated: 2018/05/06 18:50:02 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_helper(unsigned int beginning, unsigned int end, char const *s)
{
	unsigned int	i;
	char			*trimmed;

	i = -1;
	if ((trimmed = (char *)malloc((end - beginning) + 1)) == NULL)
		return (NULL);
	while (beginning <= end)
	{
		trimmed[++i] = s[beginning];
		beginning++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	beginning;
	unsigned int	end;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	beginning = i;
	while (s[i + 1])
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	i++;
	end = i;
	return (ft_helper(beginning, end, s));
}
