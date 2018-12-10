/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:11:52 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/07 11:44:48 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_piece			*init_piece(int alpha)
{
	t_piece			*piece;
	t_point			bloc;
	int				i;

	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	i = 0;
	piece->alphabet = 'A' + alpha;
	while (i < 4)
	{
		bloc = set_point(-1, -1);
		piece->blocs[i] = bloc;
		++i;
	}
	return (piece);
}

int				big_while(int *i, int *diese, char *s, t_piece *piece)
{
	int		j;
	int		a;
	int		b;

	b = *diese;
	a = *i;
	j = 0;
	while (++a < 20)
	{
		if (s[a] != '.' && s[a] != '#' && s[a] != '\n')
			return (1);
		if (s[a] == '.' || s[a] == '#')
			++j;
		if (s[a] == '\n' && j != 4)
			return (1);
		else if (s[a] == '\n' && j == 4)
			j = 0;
		if (s[a] == '#' && ++b < 4)
			piece->blocs[b] = set_point(a % 5, a / 5);
		else if (s[a] == '#' && b >= 4)
			return (1);
	}
	*diese = b;
	*i = a;
	return (0);
}

t_piece			*add_piece(char *s, int alpha)
{
	t_piece		*piece;
	int			*i;
	int			*diese;
	int			a;
	int			b;

	i = NULL;
	diese = NULL;
	a = -1;
	b = -1;
	i = &a;
	diese = &b;
	if ((piece = init_piece(alpha)) == NULL)
		return (NULL);
	if ((big_while(i, diese, s, piece)))
		return (free_piece(piece));
	if ((alpha != 0 && s[a] != '\n') || b != 3)
		return (free_piece(piece));
	return (check_piece(piece));
}

t_fillit		*get_piece(t_fillit *all, int fd)
{
	char	*buff;
	t_piece	*piece;
	int		i;
	int		last_read;
	int		reading;

	if ((buff = ft_strnew(21)) == NULL)
		return (NULL);
	i = 0;
	last_read = -1;
	while ((reading = read(fd, buff, 21)))
	{
		if ((piece = add_piece(buff, i)) == NULL || i >= 26)
		{
			free(piece);
			return (norme(fd, buff, 1, all));
		}
		all->nb_piece = i + 1;
		all->pieces[i++] = *piece;
		free(piece);
		last_read = reading;
	}
	if (last_read != 20 || reading != 0)
		return (norme(fd, buff, 1, all));
	return (norme(fd, buff, 0, all));
}

t_fillit		*open_file(char *file, t_fillit *all)
{
	int		fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if ((all = get_piece(all, fd)) == NULL)
		return (NULL);
	if (all->nb_piece > 26)
		return (NULL);
	return (all);
}
