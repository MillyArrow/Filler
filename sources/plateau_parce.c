/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau_parce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:18:41 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 16:26:43 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		plateau_parse(t_filler *filler, char *line)
{
	int i;
	int j;
	char **split_line;

	i = 0;
	j = 0;
	if (!(split_line = ft_strsplit(line,' ')))
		return (NULL);
	filler->plateau->height = ft_atoi(split_line[1]);
	filler->plateau->width = ft_atoi(split_line[2]);
	filler->plateau->heat_map = (char **)ft_memalloc(
		sizeof(char) * (filler->plateau->height + 1));
	

}
