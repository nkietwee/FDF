/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:44 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/11 16:24:01 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_addnbr(t_fillnbr *nbr, char *av)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	nbr->node = (t_point **)malloc(sizeof(t_point ) * (nbr->col));
	if (!nbr->node)
		return ;
	while(1)
	{
		nbr->node[i] = (t_point *)malloc(sizeof(t_point ) * (nbr->row));
		if (!nbr->node[i])
			return ;
		
	}
}
