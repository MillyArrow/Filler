/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:51:33 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 18:48:15 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

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
	char		**map;
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



#endif
