/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:35:27 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 07:43:00 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parse_piece(t_filler *filler, char *line)
{
	int		i;
	int		j;

	i = 0;
	while(i < filler->piece->height && get_next_line(0,(&line)))
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

void	parse_plateau(t_filler *filler,char *line)
{
	int		i;
	int		j;
	int		space_i;

	i = -1;
	while(i < filler->plateau->height && get_next_line(0,(&line)))
	{
		space_i = ft_strchri(line,' ') + 1;
		j = 0;
		while (j < filler->plateau->width)
		{
			if ((line + space_i)[j] == '.')
				filler->plateau->heat_map[i][j] = 0;
			else if (ft_toupper((line + space_i)[j]) == 'O' ||
			ft_toupper((line + space_i)[j]) == 'X')
			{
				if ((ft_toupper((line + space_i)[j]) == 'O' &&
				filler->player == 'O') ||
				(ft_toupper((line + space_i)[j]) == 'X' &&
				filler->player == 'X'))
					filler->plateau->heat_map[i][j] = PLAYER;
				else
					filler->plateau->heat_map[i][j] = ENEMY;
			}
			j++;
		}
		if (line)
			ft_strdel(&line);
		i++;
	}
}
