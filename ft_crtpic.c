/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:27:08 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 01:25:45 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_findmax(float dx, float dy)
{
	if (dx > dy)
		return (dx);
	return (dy);	
}

void	ft_dda(t_point *start, t_point *end, t_keyhook *crt)
{
	t_drawline	point;

	point.i = 0;
	point.dx = end->x - start->x;
	point.dy = end->y - start->y;
	point.step = ft_findmax(ft_abs(point.dx), ft_abs(point.dy));
	point.x_incre = point.dx / point.step;
	point.y_incre = point.dy / point.step;
	point.tmp_start_x = start->x;
	point.tmp_start_y = start->y;
	while (point.i < point.step)
	{
		point.tmp_start_x = point.tmp_start_x + point.x_incre;
		point.tmp_start_y = point.tmp_start_y + point.y_incre;
		my_mlx_pixel_put(&crt->img, (int)(point.tmp_start_x + 400),\
		(int)(point.tmp_start_y - 250), start->color);
		point.i++;
	}
}


void	ft_createline(t_fillnbr *nbr, t_keyhook *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < nbr->row)
	{
		i = 0;
		while (i < nbr->col - 1)
		{
			if (i < nbr->col - 1)
				ft_dda(&nbr->node[i][j], &nbr->node[i + 1][j], img);
			if (j < nbr->row - 1)
				ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img);
			i++;
		}
		if (i == nbr->col - 1 && j < nbr->row - 1)
			ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img);	
		j++;
	}
}

void	ft_setratio(t_fillnbr *nbr)
{
	float	i;

	i = 0;
	while (i < WIN_WIDTH / (((nbr->row + nbr->col)) * cos(ANGLE)) * MAGIC)
		i++;
	nbr->ratio = i;
}

void	ft_isometric(t_fillnbr *nbr, t_keyhook *crt)
{
	float	x_keep;
	float	y_keep;
	int		i;
	int		j;
	(void)crt;

	i = 0;
	while (i < nbr->col)
	{
		j = 0;
		while (j < nbr->row)
		{
			x_keep = nbr->node[i][j].x;
			y_keep = nbr->node[i][j].y;
			nbr->node[i][j].x = (x_keep - y_keep) * cos(ANGLE);
			nbr->node[i][j].y = ((x_keep + y_keep) * sin(ANGLE)) - nbr->node[i][j].z;
			// my_mlx_pixel_put(&crt->img, (int)(nbr->node[i][j].x ), (int)(nbr->node[i][j].y) , nbr->node[i][j].color);
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
	return(0);
}


void	ft_setcenter(t_fillnbr *nbr)
{
	float	x_map;
	float	y_map;
	float	x_cen;
	float	y_cen;

	nbr->i = 0;
    x_map =  nbr->col / 2 * nbr->ratio;
	y_map =  nbr->row / 2 * nbr->ratio;
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

void	ft_resetdata(t_fillnbr *nbr, t_point *value, t_keyhook *data)
{
	(void)value;
	ft_setratio(nbr);
	ft_setcenter(nbr);
	ft_isometric(nbr, data);
}

void	ft_create(t_fillnbr *nbr, t_keyhook *data)
{
	ft_resetdata(nbr, *nbr->node, data);
	ft_createline(nbr, data);
}
