/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:00:09 by feedme            #+#    #+#             */
/*   Updated: 2018/05/06 22:52:32 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_counts_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
		i++;
	}
	return (count);
}

static char				*ft_putword(char const *s, char c, unsigned int i)
{
	char			*tmp;
	unsigned int	size;
	unsigned int	i0;
	unsigned int	x;

	x = 0;
	size = 0;
	i0 = i;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	if ((tmp = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	while (i0 != i)
	{
		tmp[x] = s[i0];
		x++;
		i0++;
	}
	tmp[x] = '\0';
	return (tmp);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int	word_count;

	FELIX1;
	if (s == NULL)
		return (NULL);
	word_count = ft_counts_words(s, c);
	if ((array = (char **)malloc(sizeof(char *) * (word_count + 1))) == NULL)
		return (NULL);
	while (j < word_count)
	{
		if (s[i] == c)
			i++;
		else
		{
			array[j] = ft_putword(s, c, i);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	array[j] = NULL;
	return (array);
}
