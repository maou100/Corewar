/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:47:50 by feedme            #+#    #+#             */
/*   Updated: 2018/07/25 14:11:14 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 10
# define MACRO int ret; char *tmp;
# define MACRO1 !(tab[fd] = ft_strsub(tab[fd], 1, ft_strlen(tab[fd]) - 1))
# define MACRO2 !(*line = ft_join(*line, buf))

int		get_next_line(int const fd, char **line);

#endif
