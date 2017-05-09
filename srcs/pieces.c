/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 00:11:38 by iwagner           #+#    #+#             */
/*   Updated: 2017/04/06 00:19:42 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pieces.h"
#include "fillit.h"

void	ft_store(int p1, int p2, int piece, int **queue)
{
	queue[0][piece] = p1;
	queue[1][piece] = p2;
	return ;
}

int		ft_find_pieces(char **str, int x, int piece, int **queue)
{
	int		i;
	int		c;
	int		y;

	c = 0;
	y = 0;
	while (str[x][y] == '.')
	{
		y++;
		if (str[x][y] == '\n')
			y = ++x * 0;
	}
	i = 0;
	while (i < 20)
	{
		if (str[x + g_c[i][0][c].i][y + g_c[i][1][c].i] == '#')
			ft_store(g_c[i][0][c].i, g_c[i][1][c].i, piece + c, queue);
		else
			c = 0 * ++i;
		if (c++ >= 4)
			return (1);
	}
	return (0);
}

int		ft_count_pieces(char *tetr, int c, int split)
{
	while (*tetr)
		if (*tetr++ == c)
			split++;
	if (split % 4 != 0)
		return (0);
	return (split / 4);
}

char	**ft_pieces(char *tetr)
{
	char	**ret;
	size_t	x;
	size_t	z;

	x = 0;
	ret = (char**)malloc(sizeof(char*) * 500);
	while (*tetr)
	{
		z = x + 4;
		while (x < z)
		{
			ret[x] = (char*)malloc(sizeof(char) * 5);
			ft_strncpy(ret[x], tetr, 5);
			tetr += 5;
			x++;
		}
		ret[x] = "\n";
		x++;
		tetr++;
	}
	return (ret);
}

int		ft_pieces_stuff(int *t_pic, int ac, char **av, int **queue)
{
	int		is;
	char	*tetr;
	char	**tetris;
	int		piece;
	int		pieces_left;

	is = -5;
	piece = 0;
	pieces_left = 0;
	if (!(tetr = ft_file_grid(ac, av[1])))
		return (0);
	if (!(t_pic[0] = ft_count_pieces(tetr, '#', 0)))
		return (0);
	if (t_pic[0] > 26 || !(ft_validate(tetr, t_pic[0])))
		return (0);
	tetris = ft_pieces(tetr);
	free(tetr);
	while (pieces_left++ < t_pic[0])
	{
		if (!(ft_find_pieces(tetris, is += 5, piece, queue)))
			return (0);
		piece += 4;
	}
	free(tetris);
	return (1);
}
