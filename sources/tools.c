/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:57:00 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 07:46:11 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_player(t_filler *filler, char *line)
{
	while (get_next_line(FD, &line) > 0)
	{
		if (line && !ft_strncmp(line, "$$$ exec", 8))
			break ;
	}
	if (ft_strstr(line, NAME) && ft_strstr(line, "p1"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (ft_strstr(line, NAME) && ft_strstr(line, "p2"))
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	return (filler->player && filler->enemy ? 1 : 0);
}

int		get_size(int *height, int *width, char *line)
{
	char **split_line;

	if (!(split_line = ft_strsplit(line, ' ')))
		return (0);
	*height = ft_atoi(split_line[1]);
	*width = ft_atoi(split_line[2]);
	ft_arrdel((void ***)&split_line);
	return (1);
}

int		create_map(t_filler *filler, char *line)
{
	int j;

	j = 0;
	if (!get_size(&filler->plateau->height,
	&filler->plateau->width, line))
		return (0);
	if (!(filler->plateau->heat_map =
	(int **)ft_memalloc(sizeof(int *) * (filler->plateau->height))))
		return (0);
	while (j < filler->plateau->height)
	{
		if (!(filler->plateau->heat_map[j] = (int *)ft_memalloc(sizeof(int) *
				(filler->plateau->width))))
		{
			ft_memdel((void **)filler->plateau->heat_map);
			return (0);
		}
		j++;
	}
	return (1);
}

int			create_piece(t_filler *filler, char *line)
{
	int i;

	i = 0;
	if (!(get_size(&filler->piece->height,
	&filler->piece->width, line)))
		return (0);
	if (!(filler->piece->map =
	(int **)ft_memalloc(sizeof(int *) * (filler->piece->height))))
		return (0);
	while (i < filler->piece->height)
	{
		if (!(filler->piece->map[i] = (int *)ft_memalloc(sizeof(int) *
				(filler->piece->width))))
		{
			ft_memdel((void **)filler->piece->map);
			return (0);
		}
		i++;
	}
	return (1);
}

void		free_filler(t_filler *filler)
{
	if (filler->plateau->heat_map)
		ft_arrdel((void ***)&filler->plateau->heat_map);
	if (filler->piece->map)
		ft_arrdel((void ***)&filler->piece->map);
}
