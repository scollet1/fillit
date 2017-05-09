/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:34:30 by iwagner           #+#    #+#             */
/*   Updated: 2017/04/10 19:59:31 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_remove_piece(int *t_pic, int piece, char **grid)
{
	int		row;
	int		col;

	row = 0;
	while (grid[row][0])
	{
		col = 0;
		while (grid[row][col])
		{
			if (grid[row][col] == t_pic[0] - (t_pic[0] - (piece / 4)) + 'A')
				grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return (grid);
}

int		ft_get_piece(char ch)
{
	return ((ch - 'A') * 4);
}

char	ft_getch(int piece, int *t_pic)
{
	char	ch;

	ch = t_pic[0] - (t_pic[0] - (piece / 4)) + 'A';
	return (ch);
}

int		ft_place_piece(int i, int **queue, char **grid, char ch)
{
	int		row;
	int		col;
	int		ctr;
	int		pic;
	int		z;

	ctr = 0;
	z = ft_strlen(*grid);
	row = (z > 0) ? i / z : 0;
	col = (z > 0) ? i % z : 0;
	pic = ft_get_piece(ch);
	while (ctr < 4)
	{
		if (grid[row + queue[0][ctr + pic]][col + queue[1][ctr + pic]] == '.')
			grid[row + queue[0][ctr + pic]][col + queue[1][ctr + pic]] = ch;
		else
			return (0);
		ctr++;
	}
	return (1);
}

int		solve_fillit(int **queue, char **grid, int piece, int *t_pic)
{
	int		i;
	int		z;
	char	ch;

	i = 0;
	z = ft_strlen(*grid);
	ch = ft_getch(piece, t_pic);
	if (piece == t_pic[0] * 4)
		return (1);
	while (i < z * z)
	{
		if (ft_place_piece(i, queue, grid, ch))
		{
			if (solve_fillit(queue, grid, piece + 4, t_pic) == 0)
				ft_remove_piece(t_pic, piece, grid);
			else
				return (1);
		}
		else
			ft_remove_piece(t_pic, piece, grid);
		i++;
	}
	return (0);
}
