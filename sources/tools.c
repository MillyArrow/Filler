/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:57:00 by marrow            #+#    #+#             */
/*   Updated: 2020/10/18 20:01:36 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_player(t_filler *filler, char **line)
{
	while (get_next_line(0,&line) > 0)
	{
		if (line && !ft_strncmp(line, "$$$ exec",8))
			break;
	}
	if (ft_strstr(line,NAME) && ft_strstr(line, "p1"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (ft_strstr(line,NAME) && ft_strstr(line, "p2"))
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	return (filler->player && filler->enemy ? 1 : 0);
}

int		get_size(int *height, int *width, char *line)
{
	char **split_line;

	if (!(split_line = ft_strsplit(line,' ')))
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
	while(j < filler->plateau->height)
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
		i++;
	}
}

int			create_piece(t_filler *filler,char *line)
{
	int i;

	i = 0;
	if (!(get_size(&filler->piece->height,
	&filler->piece->width, line)))
		return(0);
	if (!(filler->piece->map =
	(int **)ft_memalloc(sizeof(int *) * (filler->piece->height))))
		return (0);
	while(i < filler->piece->height)
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
		i++;
	}
}
void		free_filler(t_filler *filler,char *line)
{
	if (filler->plateau->heat_map)
		ft_arrdel((void ***)&filler->plateau->heat_map);
	if (filler->piece->map)
		ft_arrdel((void ***)&filler->piece->map);
	if (line)
		ft_strdel(&line);
}