#include "filler.h"

void calc_heat_map(t_filler *filler)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < filler->plateau->height)
    {
		j = 0;
		while (j < filler->plateau->width) {
			if (filler->plateau->heat_map[i][j] != 1 &&
				filler->plateau->heat_map[i][j] != -1)
				filler->plateau->heat_map[i][j] = calc_distance(filler, i, j);
			j++;
		}
		i++;
	}
}

int manhattan_distance(int x, int y, int i, int j) // A(x,y) B(i,j)
{
    int distance;

    distance = ABS((x - i)) + ABS((y - j));
    return (distance);
}

int	calc_distance(t_filler *filler, int x, int y)
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
			if (filler->plateau->heat_map[i][j] == -1 &&
			manhattan_distance(x,y,i,j) < result)
				result = manhattan_distance(x,y,i,j);
			j++;
		}
		i++;
	}
	return (result);
}

int sum_around(t_filler *filler, int x, int y)
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
			if (filler->piece->map[i][j] == 1 && filler->plateau->heat_map[i + x][j + y] == 1)
				sum += filler->plateau->heat_map[i + x][j + y];
			j++;
		}
		i++;
	}
	return (sum);
}

void	put_piece(t_filler *filler)
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