/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 13:31:34 by mac               #+#    #+#             */
/*   Updated: 2020/05/09 20:18:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_setcolor(char *str, size_t *i, t_spec *specifier)
{
	int		j;

	(*i)++;
	j = 0;
	while (str[*i] != '}')
	{
		specifier->color[j] = str[*i];
		(*i)++;
		j++;
	}
	(*i)++;
	specifier->color[j] = '\0';
	if (!ft_strcmp(specifier->color, "black"))
		ft_putstrs(BLACK, specifier);
	if (!ft_strcmp(specifier->color, "red"))
		ft_putstrs(RED, specifier);
	if (!ft_strcmp(specifier->color, "yellow"))
		ft_putstrs(YELLOW, specifier);
	if (!ft_strcmp(specifier->color, "cyan"))
		ft_putstrs(CYAN, specifier);
	if (!ft_strcmp(specifier->color, "eoc"))
		ft_putstrs(EOC, specifier);
	return (0);
}
