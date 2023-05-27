/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:27:08 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/27 14:03:55 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_fillnbr *nbr)
{
	float	x_keep;
	float	y_keep;
	int		i;
	int		j;

	i = 0;
	while (i < nbr->col)
	{
		j = 0;
		while (j < nbr->row)
		{
			x_keep = nbr->node[i][j].x;
			y_keep = nbr->node[i][j].y;
			nbr->node[i][j].x = (x_keep - y_keep) * cos(ANGLE);
			nbr->node[i][j].y = ((x_keep + y_keep) * sin(ANGLE))
				- nbr->node[i][j].z;
			j++;
		}
		i++;
	}
}

float	ft_isomap(float x_map, float y_map, char axis)
{
	if (axis == 'x')
		return ((x_map - y_map) * cos(ANGLE));
	if (axis == 'y')
		return ((x_map + y_map) * sin(ANGLE));
	return (0);
}

void	ft_setcenter(t_fillnbr *nbr)
{
	float	x_map;
	float	y_map;
	float	x_cen;
	float	y_cen;

	nbr->i = 0;
	x_map = (nbr->col / 2) * nbr->ratio;
	y_map = (nbr->row / 2) * nbr->ratio;
	x_cen = (float)WIN_WIDTH_CEN - (ft_isomap(x_map, y_map, 'x'));
	y_cen = (float)WIN_HEIGHT_CEN - (ft_isomap(x_map, y_map, 'y'));
	while (nbr->i < nbr->col)
	{
		nbr->j = 0;
		while (nbr->j < nbr->row)
		{
			nbr->node[nbr->i][nbr->j].x = nbr->node[nbr->i][nbr->j].x + x_cen;
			nbr->node[nbr->i][nbr->j].y = nbr->node[nbr->i][nbr->j].y + y_cen;
			nbr->j++;
		}
		nbr->i++;
	}
}

void	ft_create(t_fillnbr *nbr, t_keyhook *data)
{
	ft_setcenter(nbr);
	ft_isometric(nbr);
	ft_createline(nbr, data);
}
