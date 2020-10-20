/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:35:27 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 08:11:23 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parse_piece(t_filler *filler, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->piece->height && get_next_line(FD, (&line)))
	{
		j = 0;
		while (j < filler->piece->width)
		{
			if (line[j] == '.')
				filler->piece->map[i][j] = 0;
			else if (line[j] == '*')
				filler->piece->map[i][j] = 1;
			j++;
		}
		if (line)
			ft_strdel(&line);
		i++;
	}
}

void			fck_norm(t_filler *filler, int *space_i, int *i, char *line)
{
	int j;

	j = 0;
	while (j < filler->plateau->width)
	{
		if ((line + *space_i)[j] == '.')
			filler->plateau->heat_map[*i][j] = 0;
		else if (ft_toupper((line + *space_i)[j]) == 'O' ||
				 ft_toupper((line + *space_i)[j]) == 'X')
		{
			if ((ft_toupper((line + *space_i)[j]) == 'O' &&
				 filler->player == 'O') ||
				(ft_toupper((line + *space_i)[j]) == 'X' &&
				 filler->player == 'X'))
				filler->plateau->heat_map[*i][j] = PLAYER;
			else
				filler->plateau->heat_map[*i][j] = ENEMY;
		}
		j++;
	}
}

void		parse_plateau(t_filler *filler, char *line)
{
	int		i;
	int		space_i;

	i = -1;
	while (i < filler->plateau->height && get_next_line(FD, (&line)))
	{
		space_i = ft_strchri(line, ' ') + 1;
		fck_norm(filler, &space_i, &i, line);
		if (line)
			ft_strdel(&line);
		i++;
	}
}
