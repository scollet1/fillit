/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:01:26 by scollet           #+#    #+#             */
/*   Updated: 2017/04/10 19:56:59 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		ft_validate(char *s, int num_boards)
{
	int		count_;
	int		count_newline;
	int		count_dots;

	while (num_boards-- > 0)
	{
		count_newline = 0;
		count_ = 0;
		count_dots = 0;
		while (count_newline <= 3)
		{
			count_ += (*s == '#') ? 1 : 0;
			count_dots += (*s == '.') ? 1 : 0;
			count_newline += (*s == '\n') ? 1 : 0;
			++s;
		}
		s++;
		if (count_newline != 4 || count_dots / 3 != count_)
			return (0);
	}
	return (1);
}

char	*ft_file_grid(int ac, char *av)
{
	char	buf[BUF_SIZE + 1];
	int		fd;
	char	*res;
	int		ret;
	size_t	total_size;

	total_size = 0;
	res = (char*)malloc(42);
	*res = '\0';
	if (ac == 2)
	{
		fd = open(av, O_RDONLY);
		(ret = read(fd, buf, BUF_SIZE));
		total_size += ret;
		res = (char*)malloc(sizeof(char) * (ret + 1));
		*res = '\0';
		buf[ret] = '\0';
		ft_strcat(res, buf);
		close(fd);
		if (ret % 21 != 20)
			return (0);
	}
	else
		return (0);
	return (res);
}

int		main(int ac, char **av)
{
	int		*t_pic;
	char	**grid;
	int		cur_size;
	int		**queue;

	if (ac == 2)
	{
		if (!(t_pic = (int*)malloc(sizeof(int))))
			return (0);
		cur_size = 2;
		queue = (int**)malloc(sizeof(int*) * 2);
		if (!(queue[0] = (int*)malloc(sizeof(int) * 109)))
			return (0);
		if (!(queue[1] = (int*)malloc(sizeof(int) * 109)))
			return (0);
		if (!(ft_pieces_stuff(t_pic, ac, av, queue)))
			return (ft_error());
		grid = (char**)malloc(sizeof(char*) * 18);
		ft_make_grid(grid);
		ft_grow_grid(grid, cur_size);
		while (solve_fillit(queue, grid, 0, t_pic) == 0)
			ft_grow_grid(grid, cur_size++);
		return (display(grid, cur_size));
	}
	return (ft_error());
}
