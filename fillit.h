/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:11:59 by reda-con          #+#    #+#             */
/*   Updated: 2018/12/07 11:44:09 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/inc/libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_piece
{
	char		alphabet;
	t_point		blocs[4];
}				t_piece;

typedef struct	s_fillit
{
	t_piece		pieces[26];
	int			max_pos;
	int			nb_piece;
	char		**map;
}				t_fillit;

t_fillit		*open_file(char *file, t_fillit *all);
int				init_all(t_fillit *data);
char			**init_map(t_fillit *data);
int				fillit(t_fillit *data);
t_piece			*check_piece(t_piece *piece);
t_point			next_pos(t_point act_pos, t_fillit *data);
t_point			set_point(int x, int y);
char			**refill_dot(int size, char **map, char c);
void			free_map(t_fillit *data);
t_piece			*free_piece(t_piece *piece);
void			print_result(t_fillit *final);
int				error(t_fillit *all);
t_fillit		*norme(int fd, char *buff, int flag, t_fillit *all);

#endif
