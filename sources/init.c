/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:55:54 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 18:50:15 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_player(t_filler *filler, char *line)
{

}

int		init_filler()
{
	t_filler *filler;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->player = 0;
		filler->enemy = 0;
		filler->x = 0;
		filler->y = 0;
		filler->plateau = init_plateau();
		filler->piece = init_peace();
	}
	return (filler);
}

int		init_plateau()
{
	t_plateau *plateau;
	if ((plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
	{
		plateau->width = 0;
		plateau->height = 0;
		plateau->heat_map = NULL;
	}
	return (plateau);
}

int		init_piece()
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
