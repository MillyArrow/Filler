/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:57:00 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 22:14:09 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_player(t_filler *filler, char *line)
{
	if (ft_strstr(line,NAME) && ft_strstr(line, "p1"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	return (filler->player && filler->enemy ? 1 : 0);
}

int		get_size(int *height, int *width, char *line)
{
	int i;
	int j;
	char **split_line;

	i = 0;
	j = 0;
	if (!(split_line = ft_strsplit(line,' ')))
		return (0);

		ft_printf("%s \n",split_line[2]);
	*height = ft_atoi(split_line[1]);
	write(1,"c",1);
	*width = ft_atoi(split_line[2]);
	ft_sdel((void ***)&split_line);
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
	(int **)ft_memalloc(sizeof(int) * filler->plateau->height + 1)))
		return (0);
	while(j < filler->plateau->height)
	{
		if (!(filler->plateau->heat_map[j] = (int *)ft_memalloc(sizeof(int) *
		filler->plateau->width)))
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

	i = 0;
	j = 0;
	while(i < filler->plateau->height && get_next_line(0,&line))
	{
		j = 0;
		while (j < filler->plateau->width)
		{
			filler->plateau->heat_map[i][j] = '0';
			j++;
		}
		i++;
	}
}
