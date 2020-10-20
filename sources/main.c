/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:51:04 by marrow            #+#    #+#             */
/*   Updated: 2020/10/20 07:47:49 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main()
{
	t_filler	*filler;
	char		*line;

	filler = NULL;
	line = NULL;
	if (!(filler = init_filler()) || !check_player(filler, line))
		return (0);
	if (!solve(filler,line))
		return(0);
	return (0);
}
