/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:51:33 by marrow            #+#    #+#             */
/*   Updated: 2020/10/15 17:26:17 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# define NAME "marrow.filler"
# define TRUE 1
# define FALSE 0

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

//FUNCTIONS

t_filler		*init_filler();
t_plateau		*init_plateau();
t_piece			*init_piece();
int				solve();
int				check_player(t_filler *filler, char *line);
int				get_size(int *height, int *width, char *line);
int				create_map(t_filler *filler, char *line);
int				create_piece(t_filler *filler,char *line);
void			parse_plateau(t_filler *filler,char *line);
void			parse_piece(t_filler *filler, char *line);

#endif
