/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:55:54 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 21:32:57 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler		*init_filler()
{
	t_filler *filler;

	filler = NULL;
	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->player = 0;
		filler->enemy = 0;
		filler->x = 0;
		filler->y = 0;
		filler->plateau = NULL;
		filler->piece = NULL;
	}
	return(filler);
}

t_plateau		*init_plateau()
{
	t_plateau *plateau;
	if ((plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
	{
		plateau->width = 0;
		plateau->height = 0;
		plateau->heat_map = NULL;
	}
	return(plateau);
}

t_piece			*init_piece()
{
	t_piece		*piece;
	if ((piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
	{
		piece->height = 0;
		piece->width = 0;
		piece->map = NULL;
	}
	return(piece);
}
