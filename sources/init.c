/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:55:54 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 16:21:36 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		player_init(t_filler *filler, char *line)
{

}

int		filler_init()
{
	t_filler *filler;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->player = 0;
		filler->enemy = 0;
		filler->x = 0;
		filler->y = 0;
		filler->plateau = plateau_init();
		filler->peace = peace_init();
	}
	return (filler);
}

int		plateau_init()
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

int		peace_init()
{
	t_peace		*peace;
	if ((peace = (t_peace *)ft_memalloc(sizeof(t_peace))))
	{
		peace->height = 0;
		peace->width = 0;
		peace->map = NULL;
	}
	return(peace);
}
