/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:27:08 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/13 16:37:33 by nkietwee         ###   ########.fr       */
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
float	ft_abs(float num)
{
	if (num < 0)
		return(-num);
	return(num);
}
// // void	ft_dda(float start, float end)
// void	ft_dda(t_point *start, t_point *end, t_keyhook *crt)
// {
// 	float	dx;
// 	float	dy;
// 	float	step;
// 	float 	x_incre;
// 	float 	y_incre;
// 	int		i;

// 	dx = end->x - start->x;
// 	dy = end->y - start->y;
// 	i = 0;
// 	if (ft_abs(dx) > ft_abs(dy))
// 		step = ft_abs(dx);
// 	else 
// 		step = ft_abs(dy);
// 	x_incre = dx / step;
// 	y_incre = dy / step;
// 	while (i < step)
// 	{
// 		start->x = start->x + x_incre;
// 		start->y = start->y + y_incre;
// 		my_mlx_pixel_put(&crt->img, (int)(start->x), (int)(start->y), WHITE_CL); //put point
// 		// put pixel(start->x, start->y)
// 	}
// }
void	ft_dda(t_point *start, t_point *end, t_keyhook *crt)
{
	float	dx;
	float	dy;
	float	step;
	float 	x_incre;
	float 	y_incre;
	int		i;

	dx = end->x - start->x;
	dy = end->y - start->y;
	// printf("dx : %f\n" ,dx);
	// printf("dy : %f\n" ,dy);
	i = 0;
	if (ft_abs(dx) > ft_abs(dy))
		step = ft_abs(dx);
	else 
		step = ft_abs(dy);
	// printf("step : %f\n" ,step);
	x_incre = dx / step;
	y_incre = dy / step;
	// printf("x_incre : %f\n" ,x_incre);
	// printf("y_incre : %f\n" ,y_incre);
	while (i < step)
	{
		start->x = start->x + x_incre;
		start->y = start->y + y_incre;
		// printf("x_start : %f\n" ,start->x);
		// printf("y_start : %f\n" ,start->y);
		// exit(0);
		my_mlx_pixel_put(&crt->img, (int)(start->x), (int)(start->y), WHITE_CL); //put point
		i++;
		// put pixel(start->x, start->y)
	}
}


void	ft_creteline(t_fillnbr *nbr, t_keyhook *img)
{
	int	i;
	int	j;

    i = 0;
    j = 0;
	while (i < nbr->row) // horizontal
	{
		j = 0;
		while (j < (nbr->col - 1))
		{
			ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < nbr->col) // vertical
	{
		i = 0;
		while (i < nbr->row - 1)
		{
			printf("[i][j] : [%d][%d]\n" ,i,j);
			ft_dda(&nbr->node[i][j], &nbr->node[i + 1][j], img);
			i++;
		}
		j++;
	}
	// exit(0);
}

void	ft_setratio(t_fillnbr *nbr)
{
	float	i;

	i = 0;
	while(i * (nbr->row + nbr->col) < WIN_HEIGHT * VAL_30 * MAGIC)
	{
		i++;
	}
	nbr->ratio = i;
	// printf("%d\n" ,nbr->ratio);
	// exit(0);
}

// void	ft_isometric(float *x, float *y, float *z, float ratio)
void	ft_isometric(t_fillnbr *nbr)
{
	float x_keep;
	float y_keep;
	int	i;
	int	j;

	i = 0;
	// printf("ratio : %d\n" , nbr->ratio);	
	while (i < nbr->row)
	{
		x_keep = nbr->node[i][j].x;
		y_keep = nbr->node[i][j].y;
		j = 0;
		while (j < nbr->col)
		{
			x_keep = nbr->node[i][j].x;
			y_keep = nbr->node[i][j].y;
			// printf("x_keep[%d][%d] : %.3f\n" , i, j ,x_keep);
			// printf("y_keep[%d][%d] : %.3f\n" , i, j ,y_keep);
			
			// nbr->node[i][j].x = (x_keep - y_keep) * cos(ANGLE) * nbr->ratio;
			// nbr->node[i][j].y = ((x_keep + y_keep) * sin(ANGLE) - nbr->node[i][j].z) * nbr->ratio;
			nbr->node[i][j].x = (x_keep - y_keep) * cos(ANGLE);
			nbr->node[i][j].y = ((x_keep + y_keep) * sin(ANGLE) - nbr->node[i][j].z);
			// printf("x_iso[%d][%d] : %.3f\n" , i, j ,nbr->node[i][j].x);
			// printf("y_iso[%d][%d] : %.3f\n" , i, j ,nbr->node[i][j].y);
			// exit(0);
			j++;
		}
		i++;
	}
	// exit(0);
}

void	ft_setcenter(t_fillnbr *nbr)
{
	float	x_move;
	float	y_move;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// x_move =  (WIN_WIDTH / 2) + (nbr->row / 2);
    // y_move =  (WIN_HEIGHT / 2) + (nbr->col / 2);
    x_move =  (WIN_WIDTH_CEN) - (nbr->col / 2);
	y_move =  (WIN_HEIGHT_CEN) - (nbr->row / 2);
	
	while (i < nbr->row)
	{
		j = 0;
		while (j < nbr->col)
		{
			nbr->node[i][j].x = nbr->node[i][j].x + x_move; 
			nbr->node[i][j].y = nbr->node[i][j].y + y_move; 
			// printf("x_cen[%d][%d] :%.3f\n" , i, j ,nbr->node[i][j].x);
			// printf("y_cen[%d][%d] :%.3f\n" , i, j ,nbr->node[i][j].y);
			// exit(0);
			j++;
		}
		i++;
	}
	// exit(0);
}


void	ft_resetdata(t_fillnbr *nbr, t_point *value)
{
	(void)value;
	// ft_setratio(nbr);
	ft_setcenter(nbr);
	ft_isometric(nbr);

}
void    ft_crete(t_fillnbr *nbr, t_keyhook *data)
{
	ft_resetdata(nbr, *nbr->node);
	// ft_isometric(nbr, data);
	ft_creteline(nbr, data);

}


// //test
// void	ft_isometric(t_fillnbr *nbr, t_keyhook *data)
// {
	
// 	// int i = 0;
// 	// int j = 0;
// 	float x_tst = 0;
// 	float y_tst = 0;
//     // (void)data;
// 	// printf("hello\n");
//     nbr->i = 0;
//     nbr->j = 0;
// 	while (nbr->i < nbr->row)
// 	{
// 		nbr->j = 0;
// 		while (nbr->j < (nbr->col))
// 		{
// 			x_tst = (nbr->node[nbr->i][nbr->j].x - nbr->node[nbr->i][nbr->j].y) * cos(ANGLE) * 20; 
// 			y_tst = (((nbr->node[nbr->i][nbr->j].x + nbr->node[nbr->i][nbr->j].y) * sin(ANGLE) )- nbr->node[nbr->i][nbr->j].z) * 20; 
// 			// printf("x_tst : %f y_tst :  %f\n", x_tst, y_tst);
// 			// printf("(%d,%d)", (int)(x_tst + 720), (int)(y_tst + 50));
// 			// ft_creteline();
// 			my_mlx_pixel_put(&data->img, (int)(x_tst + 1000), (int)(y_tst + 550), WHITE_CL); //put point
            
// 			// printf("i : %d, j : %d\n ", i ,j);
// 			nbr->j++;
// 		}
//         // printf("\n");
// 		nbr->i++;
// 	}
// }

// void	ft_isometric(float *x, float *y, float *z, float ratio)
// {
// 	float x_keep;
// 	float y_keep;

// 	x_keep = *x;
// 	y_keep = *y;
	
// 	*x = (*x - *y) * cos(ANGLE) * ratio; // ratio
// 	*y = ((*x + *y) * sin(ANGLE) - *z) * ratio; // ratio
            
// }