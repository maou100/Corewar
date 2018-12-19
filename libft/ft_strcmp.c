/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:23:14 by feedme            #+#    #+#             */
/*   Updated: 2018/04/26 15:48:39 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (c1[0] == '\0' && c2[0] == '\0')
		return (0);
	if (c1[0] == '\0')
		return (-1);
	if (c2[0] == '\0')
		return (1);
	while (c1[i] == c2[i] && c1[i] != '\0')
		i++;
	return (c1[i] - c2[i]);
}
