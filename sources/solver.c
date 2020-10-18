/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:15:16 by marrow            #+#    #+#             */
/*   Updated: 2020/10/18 20:42:03 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		solve()
{
	t_filler	*filler;
	char		*line;
	int			fd;

	fd = 0;
	line = NULL;
	filler = NULL;
	if (!(filler = init_filler()) || !check_player(filler, &line))
		return (0);
	while(get_next_line(fd,&line) > 0)
	{
		if (line && !ft_strncmp(line, "Plateau",7))
		{
			if (!filler->plateau->heat_map)
				create_map(filler,line);
			parse_plateau(filler,line);
		}
		if (line && !ft_strncmp(line, "Piece",5))
		{
			create_piece(filler,line);
			parse_piece(filler,line);
			calc_heat_map(filler);
			put_piece(filler);
			ft_printf("%d %d\n",filler->x, filler->y);
		}
		//free_filler(filler,line);
		if (filler->piece->map)
			ft_arrdel((void ***)&filler->piece->map);
		if (line)
			ft_strdel(&line);
	}




	 //debug
/*

	int		i;
	int		j;

	i = 0;
	while(i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{

			ft_printf("%-2d ",filler->plateau->heat_map[i][j]);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	write(1,"\n",1);
	i = 0;
	while(i < filler->piece->height)
	{
		j = 0;
		while (j < filler->piece->width)
		{

			ft_printf("%d ",filler->piece->map[i][j]);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	calc_heat_map(filler);
	put_piece(filler);
	ft_printf("%result: %d %d\n",filler->x, filler->y);
	i = 0;
	while(i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{

			ft_printf("%-4d",filler->plateau->heat_map[i][j]);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
*/

	return (1);
}

