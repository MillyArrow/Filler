/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:51:04 by marrow            #+#    #+#             */
/*   Updated: 2020/10/14 16:22:14 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
	t_filler	*filler;
	char		*line;
	int			fd,fd1;

	fd = 0;

	while(get_next_line(fd,&line) > 0)
	{
		if (!(filler_init()))
			return (0);
		if (line && ft_strncmp(line, "$$$ exec p1",11))
			player_init(filler, line);
		if (line && ft_strncmp(line, "Plateau",7))
			plateau_init(filler,line);
		if (line && ft_strncmp(line, "Peace",5))
			peace_init();
		if (line)
			ft_strdel(&line);
	}
	return (0);
}
