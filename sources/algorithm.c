/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:49:50 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 08:17:37 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		calc_heat_map(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{
			if (filler->plateau->heat_map[i][j] != PLAYER &&
				filler->plateau->heat_map[i][j] != ENEMY)
				filler->plateau->heat_map[i][j] = calc_distance(filler, i, j);
			j++;
		}
		i++;
	}
}

int			calc_distance(t_filler *filler, int x, int y)
{
	int i;
	int j;
	int result;

	i = 0;
	result = filler->plateau->width * filler->plateau->height;
	while (i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{
			if (filler->plateau->heat_map[i][j] == ENEMY &&
			manhattan_distance(x, y, i, j) < result)
				result = manhattan_distance(x, y, i, j);
			j++;
		}
		i++;
	}
	return (result);
}

int			calc_sum(t_filler *filler, int x, int y, int *rule)
{
	int i;
	int j;
	int sum;

	sum = 0;
	i = 0;
	while (i < filler->piece->height)
	{
		j = 0;
		while (j < filler->piece->width)
		{
			if (filler->plateau->heat_map[i + x][j + y] == PLAYER &&
				filler->piece->map[i][j] == 1)
				++(*rule);
			if ((filler->plateau->heat_map[i + x][j + y] == ENEMY &&
				filler->piece->map[i][j] == 1) || *rule > 1)
				return (0);
			if (filler->piece->map[i][j] == 1 &&
				filler->plateau->heat_map[i + x][j + y])
				sum += filler->plateau->heat_map[i + x][j + y];
			j++;
		}
		i++;
	}
	return (sum);
}

int			sum_around(t_filler *filler, int x, int y)
{
	int sum;
	int rule;

	rule = 0;
	if (x + filler->piece->height > filler->plateau->height ||
		y + filler->piece->width > filler->plateau->width)
		return (0);
	sum = calc_sum(filler, x, y, &rule);
	return (rule == 1 ? sum : 0);
}

void		put_piece(t_filler *filler)
{
	int i;
	int j;
	int sum;
	int min_sum;

	i = 0;
	min_sum = INT_MAX;
	sum = 0;
	while (i < filler->plateau->height)
	{
		j = 0;
		while (j < filler->plateau->width)
		{
			sum = sum_around(filler, i, j);
			if (sum && sum < min_sum)
			{
				min_sum = sum;
				filler->x = i;
				filler->y = j;
			}
			j++;
		}
		i++;
	}
}
