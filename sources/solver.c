/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:15:16 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 08:11:23 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			manhattan_distance(int x, int y, int i, int j)
{
	int distance;

	distance = ABS((x - i)) + ABS((y - j));
	return (distance);
}

int			solve(t_filler *filler, char *line)
{
	while (get_next_line(FD, &line) > 0)
	{
		if (line && !ft_strncmp(line, "Plateau", 7))
		{
			if (!filler->plateau->heat_map)
				if (!create_map(filler, line))
					return (0);
			parse_plateau(filler, line);
		}
		if (line && !ft_strncmp(line, "Piece", 5))
		{
			if (!create_piece(filler, line))
				return (0);
			parse_piece(filler, line);
			calc_heat_map(filler);
			put_piece(filler);
			ft_printf("%d %d\n", filler->x, filler->y);
		}
		if (filler->piece->map)
			ft_arrdel((void ***)&filler->piece->map);
		if (line)
			ft_strdel(&line);
	}
	free_filler(filler);
	return (1);
}
