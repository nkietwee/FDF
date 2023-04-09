/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:57:09 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/09 23:51:39 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// crete rectangle
void	ft_crtrectangle(float row, float *col, t_data img)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	while (y < *col)
	{
		x = 0;
		while (x < row)
		{
			my_mlx_pixel_put(&img, x, y, WHITE_CL); //put point
			x++;
		}
		y++;
	}
}

//plot point in middle window
void	ft_crtpoint_middle(t_fillnbr *nbr, t_data *img)
{
	float x_test = 0;
	float y_test = 0;

	while (y_test < nbr->row * 50)
	{
		// printf ("hello world\n");
		x_test = 0;
		while (x_test < *(nbr->col) * 50)
		{
			my_mlx_pixel_put(img, x_test + 400, y_test + 300, WHITE_CL); //put point
			x_test+= 50;
			// exit(0);
		}
		y_test+= 50;
	}


}


//crete isometric
void	ft_isometric(t_fillnbr *nbr, t_data *img)
{
	int i = 0;
	int j = 0;
	float x_tst = 0;
	float y_tst = 0;
	printf("hello\n");
	while (i < nbr->row)
	{
		j = 0;
		while (j < (*(nbr->col)))
		{
			x_tst = (nbr->arr_x[i][j] - nbr->arr_y[i][j])* cos(ANGLE) * 74;
			y_tst = (nbr->arr_x[i][j] + nbr->arr_y[i][j])* sin(ANGLE) * 74 ; //+ z (res_int)
			my_mlx_pixel_put(img, x_tst + 720, y_tst + 20, WHITE_CL); //put point
			// printf("i : %d, j : %d\n ", i ,j);
			// exit(0);
			j++;
		}
		i++;
		// printf("\n");
	}

}
