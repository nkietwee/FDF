/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:27:08 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/12 23:37:40 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_crtrectangle(int row, int col, t_data *img)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	while (y < col)
	{
		x = 0;
		while (x < row)
		{
			printf("hello from crtrcg\n");
            my_mlx_pixel_put(img, (int)x, (int)y, WHITE_CL); //put point
			x++;
		}
		y++;
	}
}


// void	ft_isometric(t_fillnbr *nbr, t_data *data)
void	ft_isometric(t_fillnbr *nbr, t_keyhook *data)
{
	// int i = 0;
	// int j = 0;
	float x_tst = 0;
	float y_tst = 0;
    // (void)data;
	// printf("hello\n");
    nbr->i = 0;
    nbr->j = 0;
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		while (nbr->j < (nbr->col))
		{
			x_tst = (nbr->node[nbr->i][nbr->j].x - nbr->node[nbr->i][nbr->j].y)* cos(ANGLE) * 50; 
			y_tst = (nbr->node[nbr->i][nbr->j].x + nbr->node[nbr->i][nbr->j].y)* sin(ANGLE) * 50; 
			// printf("x_tst : %f y_tst :  %f\n", x_tst, y_tst);
			printf("(%d,%d)", (int)(x_tst + 720), (int)(y_tst + 50));
            my_mlx_pixel_put(&data->img, (int)(x_tst + 720), (int)(y_tst + 50), WHITE_CL); //put point
            // exit(0);
            
            
			// my_mlx_pixel_put(img, x_tst + 720, y_tst + 20, WHITE_CL); //put point
			// printf("i : %d, j : %d\n ", i ,j);
			nbr->j++;
		}
        printf("\n");
		nbr->i++;
	}
}


void    ft_crete(t_fillnbr *nbr, t_keyhook *data)
{
    ft_isometric(nbr, data);


}