/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:13:20 by iwagner           #+#    #+#             */
/*   Updated: 2017/04/10 19:58:01 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 424242
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_p
{
	int			r;
	int			c;
}				t_p;

int				ft_check_placement(int row, int col, int piece);
char			*ft_file_grid(int ac, char *av);
int				ft_validate(char *s, int num_boards);
void			ft_make_grid(char **grid);
void			ft_putchar(char c);
int				display(char	**grid, int		cur_size);
char			**ft_fill_grid(int		end, char	**grid);
char			**ft_grow_grid(char **grid, int cur_size);
int				solve_fillit(int **queue, char **grid, int piece, int *t_pic);
int				ft_place_piece(int i, int **queue, char **grid, char ch);
char			ft_getch(int piece, int *t_pic);
int				ft_get_piece(char ch);
int				ft_pieces_stuff(int *t_pic, int ac, char **av,
		int **queue);
char			**ft_pieces(char *tetr);
int				ft_count_pieces(char *tetr, int c, int split);
int				ft_find_pieces(char **str, int x, int piece, int **queue);
void			ft_store(int p1, int p2, int i, int **queue);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_error();

#endif
