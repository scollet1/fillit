/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:54:39 by iwagner           #+#    #+#             */
/*   Updated: 2017/04/10 19:58:50 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_make_grid(char **grid)
{
	int row;

	row = 0;
	while (row < 18)
	{
		grid[row] = (char*)malloc(sizeof(char) * 18);
		row++;
	}
	grid[row - 1] = NULL;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		display(char **grid, int cur_size)
{
	int row;

	row = 0;
	while (row <= cur_size)
	{
		write(1, (grid[row]), cur_size + 1);
		ft_putchar('\n');
		row++;
	}
	return (0);
}

char	**ft_fill_grid(int end, char **grid)
{
	int row;
	int col;

	row = 17;
	while (--row >= 0)
	{
		col = 17;
		while (--col >= 0)
			grid[row][col] = '\0';
	}
	row = end + 1;
	while (--row >= 0)
	{
		col = end + 1;
		grid[row][col] = '\0';
		while (--col >= 0)
			grid[row][col] = '.';
	}
	return (grid);
}

char	**ft_grow_grid(char **grid, int cur_size)
{
	return (ft_fill_grid(cur_size, grid));
}
