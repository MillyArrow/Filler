/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:15:16 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 22:10:28 by marrow           ###   ########.fr       */
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
			//ft_printf("%s \n",line);
			create_map(filler,line);
			parse_plateau(filler,line);
		}
		if (line && !ft_strncmp(line, "Peace",5))
			;
		if (line)
			ft_strdel(&line);
	}
	//debug

	int		i;
	int		j;

	i = 0;
	j = 0;
	while(i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{

			ft_printf("%c ",filler->plateau->heat_map[i][j]);
			j++;
		}
		write(1,"\n",1);
		i++;
	}

	return (1);
}

