/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:58:00 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/20 02:50:53 by nkietwee         ###   ########.fr       */
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
		my_mlx_pixel_put(&crt->img, (int)(point.tmp_start_x + 400),
			(int)(point.tmp_start_y - 325), start->color);
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
		if (i == nbr->col - 1 && j < nbr->row - 1) // ->segfault
		{
			printf("--[%d][%d]--\n", i , j);
			ft_dda (&nbr->node[i][j], &nbr->node[i][j + 1], img);
		}
		// exit(0);
		j++;
	}
}
