/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:59:44 by marrow            #+#    #+#             */
/*   Updated: 2020/10/18 19:59:51 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrdel(void ***arr)
{
	void	**temp;

	if (!(*arr))
		return ;
	temp = *arr;
	while (**arr)
	{
		ft_memdel(*arr);
		(*arr)++;
	}
	ft_memdel(temp);
	temp = NULL;
	*arr = temp;
}
