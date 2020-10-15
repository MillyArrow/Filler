/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:15:16 by marrow            #+#    #+#             */
/*   Updated: 2020/10/15 17:41:09 by marrow           ###   ########.fr       */
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
	if (!(filler = init_filler()))
		return (0);
	while(get_next_line(fd,&line) > 0)
	{
		if (line && !ft_strncmp(line, "$$$ exec",8))
			if (!check_player(filler, line))
				return (0);
		if (line && !ft_strncmp(line, "Plateau",7))
		{
			create_map(filler,line);
			parse_plateau(filler,line);
		}
		if (line && !ft_strncmp(line, "Piece",5))
		{
			create_piece(filler,line);
			parse_piece(filler,line);
		}
		if (line)
				ft_strdel(&line);
	}
	//debug
	int		i;
	int		j;

	i = 0;
	while(i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{

			ft_printf("%d ",filler->plateau->heat_map[i][j]);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
	write(1,"\n",1);
	ft_printf("%d\n",filler->plateau->heat_map[0][0]);
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

	return (1);
}

