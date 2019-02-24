/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:00:39 by amagnan           #+#    #+#             */
/*   Updated: 2018/12/16 14:00:39 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

static void	get_magic_header(int fd, t_player *p)
{
	char	buf[5];

	if (read(fd, buf, 4) > 0)
		p->header.magic = (unsigned int)ft_hex_to_decimal("ea83f3");
}

static void	get_name_and_size(int fd, t_player *p)
{
	char	buf[5];
	char	*part1;
	char	*part2;
	char	*part3;
	char	*part4;
	char	*tmp;

	if (read(fd, p->header.prog_name, PROG_NAME_LENGTH))
		p->header.prog_name[PROG_NAME_LENGTH] = '\0';
	read(fd, buf, 4);
	ft_bzero(buf, ft_strlen(buf));
	if (read(fd, buf, 4))
	{
		buf[4] = '\0';
		part1 = ft_itoa_base(buf[0], 16, "0123456789abcdef");
		part2 = ft_itoa_base(buf[1], 16, "0123456789abcdef");
		part3 = ft_itoa_base(buf[2], 16, "0123456789abcdef");
		part4 = ft_itoa_base(buf[3], 16, "0123456789abcdef");
		tmp = ft_strfjoin(ft_strjoin(part1, part2), ft_strjoin(part3, part4));
		p->header.prog_size = (unsigned int)ft_hex_to_decimal(tmp);
		ft_strdel(&tmp);
	}
}

static void	get_comment(int fd, t_player *p)
{
	char	trash[4];

	if (read(fd, p->header.comment, COMMENT_LENGTH))
		p->header.comment[COMMENT_LENGTH] = '\0';
	read(fd, trash, 4);
}

static void	get_executable(int fd, t_player *p, unsigned char *arena)
{
	unsigned int	i;

	if ((i = read(fd, arena, p->header.prog_size)) < p->header.prog_size)
		ft_exit_msg("Couldn't read the executable properly\n");
	while (i < 2048)
		arena[i++] = 0;
}

int		ft_get_player(t_player *p, unsigned char *arena)
{
	get_magic_header(p->fd, p);
	get_name_and_size(p->fd, p);
	get_comment(p->fd, p);
	get_executable(p->fd, p, arena);
	return (1);
}
