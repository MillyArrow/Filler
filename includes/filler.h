/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:51:33 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 04:18:13 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# define NAME "marrow.filler"
# define PLAYER -1
# define ENEMY -2
# define FD 0
# define ABS(x) ((x > 0) ? (x) : (-x))

typedef struct	s_plateau
{
	int			height;
	int			width;
	int			**heat_map;
}				t_plateau;

typedef struct	s_piece
{
	int			height;
	int			width;
	int			**map;
}				t_piece;

typedef struct	s_filler
{
	char		player;
	char		enemy;
	t_plateau	*plateau;
	t_piece		*piece;
	int			y;
	int			x;
}				t_filler;

t_filler		*init_filler();
t_plateau		*init_plateau();
t_piece			*init_piece();
int				solve(t_filler *filler, char *line);
int				check_player(t_filler *filler, char *line);
int				get_size(int *height, int *width, char *line);
int				create_map(t_filler *filler, char *line);
int				create_piece(t_filler *filler, char *line);
void			parse_plateau(t_filler *filler, char *line);
void			parse_piece(t_filler *filler, char *line);
int				manhattan_distance(int x, int y, int i, int j);
int				calc_distance(t_filler *filler, int x, int y);
void			calc_heat_map(t_filler *filler);
void			put_piece(t_filler *filler);
int				sum_around(t_filler *filler, int x, int y);
void			free_filler(t_filler *filler);
int				calc_sum(t_filler *filler, int x, int y, int *rule);
void			fck_norm(t_filler *filler, int *space_i, int *i, char *line);

#endif
