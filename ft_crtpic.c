/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtpic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:27:08 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/16 21:35:55 by nkietwee         ###   ########.fr       */
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

float	ft_findmax(float dx, float dy)
{
	if (dx > dy)
		return (dx);
	return(dy);	
}

void	ft_dda(t_point *start, t_point *end, t_keyhook *crt)
{
	float	dx;
	float	dy;
	float	step;
	float 	x_incre;
	float 	y_incre;
	int		i;
	float	tmp_start_x;
	float	tmp_start_y;
	(void)crt;

	dx = end->x - start->x;
	dy = end->y - start->y;
	step = ft_findmax(ft_abs(dx), ft_abs(dy));
	// if (ft_abs(dx) > ft_abs(dy))
	// 	step = ft_abs(dx);
	// else 
	// 	step = ft_abs(dy);
	
	x_incre = dx / step;
	y_incre = dy / step;
	
	i = 0;
	tmp_start_x = start->x;
	tmp_start_y = start->y;
	while (i < step)
	{
		tmp_start_x = tmp_start_x + x_incre;
		tmp_start_y = tmp_start_y + y_incre;
		my_mlx_pixel_put(&crt->img, (int)(tmp_start_x + 400), (int)(tmp_start_y - 200) , start->color); //put point
		i++;
		// put pixel(start->x, start->y)
	}
}


void	ft_createline(t_fillnbr *nbr, t_keyhook *img)
{
	int	i;
	int	j;

    i = 0;
	j = 0;
	// printf("col : %d\n" ,nbr->col);
	// printf("row : %d\n" ,nbr->row);
	// exit(0);
	while (j < nbr->row)
	{
		i = 0;
		while (i < nbr->col - 1)
		{
			if (i < nbr->col - 1)
				ft_dda(&nbr->node[i][j], &nbr->node[i + 1][j], img);
				// ft_dda(&nbr->node[i][j], &nbr->node[i + 1][j], img , WHITE_CL);
			// printf("bf[%.3f][%.3f] [%.3f][%.3f]\n" , nbr->node[i][j].x, nbr->node[i][j].y, nbr->node[i + 1][j].x ,nbr->node[i + 1][j].y);
			printf("bf[%d][%d] [%d][%d] " , i, j, i + 1, j);
			if (j < nbr->row - 1)
				ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img);
			// // printf("bf[%.3f][%.3f] [%.3f][%.3f] " , nbr->node[i][j].x, nbr->node[i][j].y, nbr->node[i][j + 1].x ,nbr->node[i][j + 1].y);
			printf("at[%d][%d] [%d][%d]\n" , i, j, i, j + 1);
			i++;
		}
		if (i == nbr->col - 1 && j < nbr->row - 1 ) // in case last column
			ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img);	
		j++;
	}

	// i = nbr->col - 1;
	// j = 0;
	// while (j < nbr->row - 1)
	// {
	// 	// printf("entry\n");
	// 	// printf("out_vt[%d][%d] [%d][%d]\n" , i, j, i, j + 1);
	// 	// printf("--outvt[%d][%d] [%.3f][%.3f]\n" , i, j, nbr->node[i][j].x, nbr->node[i][j].y);
	// 	// printf("--outvt[%d][%d] [%.3f][%.3f]\n" , i, j + 1, nbr->node[i][j].x, nbr->node[i][j + 1].y);
	// 	ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img, PINK_CL);
	// 	j++;
	// }

	// while (j < nbr->row) // horizontal
	// {
	// 	i = 0;
	// 	while (i < nbr->col - 1)
	// 	{
	// 		// if (i < nbr->col - 1)
	// 		ft_dda(&nbr->node[i][j], &nbr->node[i + 1][j], img, WHITE_CL);
	// 		printf("ht[%d][%d] [%d][%d]\n" , i, j, i + 1, j);
	// 		i++;
	// 	}
	// 	j++;
	
	// }
	
	// i = 0;
	// while (i < nbr->col) //vertical
	// {
	// 	j = 0;
	// 	while (j < nbr->row - 1)
	// 	{
	// 		// if (j < nbr->row - 1)
	// 		// {
	// 		printf("--vt[%d][%d] [%d][%d]\n" , i, j, i, j + 1);
	// 		// 	printf("--vt[%d][%d] [%.3f][%.3f]\n" , i, j, nbr->node[i][j].x, nbr->node[i][j].y);
	// 		// printf("--vt[%d][%d] [%.3f][%.3f]\n" , i, j + 1, nbr->node[i][j].x, nbr->node[i][j + 1].y);
	// 		// 	// if (i == 0)
	// 		// 	// 	ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img, BLUE_CL);
	// 		// 	// else
	// 		ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img, GREEN_CL);
	// 		// }
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// i = 0;
	// j = 0;
	// while (j < nbr->row - 1)
	// {
	// 	// printf("entry\n");
	// 	// printf("out_vt[%d][%d] [%d][%d]\n" , i, j, i, j + 1);
	// 	printf("--outvt[%d][%d] [%.3f][%.3f]\n" , i, j, nbr->node[i][j].x, nbr->node[i][j].y);
	// 	printf("--outvt[%d][%d] [%.3f][%.3f]\n" , i, j + 1, nbr->node[i][j].x, nbr->node[i][j + 1].y);
	// 	ft_dda(&nbr->node[i][j], &nbr->node[i][j + 1], img, PINK_CL);
	// 	j++;
	// }
	// exit(0);



}

void	ft_setratio(t_fillnbr *nbr)
{
	float	i;

	i = 0;
	// while(i * (nbr->row + nbr->col) < WIN_WIDTH * VAL_30 * MAGIC)
	while(i  < WIN_WIDTH / (((nbr->row + nbr->col)) * cos(ANGLE)) * MAGIC)
	{
		i++;
	}
	nbr->ratio = i;
	// printf("%d\n" ,nbr->ratio);
	// exit(0);
}

void	ft_isometric(t_fillnbr *nbr , t_keyhook *crt)
{
	float x_keep;
	float y_keep;
	int	i;
	int	j;
	(void)crt;

	i = 0;
	// printf("ratio : %d\n" , nbr->ratio);	
	while (i < nbr->col)
	{
		j = 0;
		while (j < nbr->row)
		{
			x_keep = nbr->node[i][j].x;
			y_keep = nbr->node[i][j].y;
			// printf("at [%d][%d] :[%.3f][%.3f]\n" , i, j ,nbr->node[i][j].x, nbr->node[i][j].y);
			// printf("at [%d][%d] :[%.3f][%.3f]\n" , i, j , x_keep, y_keep);
			// my_mlx_pixel_put(&crt->img, (int)(nbr->node[i][j].x ), (int)(nbr->node[i][j].y) , WHITE_CL);
			nbr->node[i][j].x = (x_keep - y_keep) * cos(ANGLE);
			nbr->node[i][j].y = ((x_keep + y_keep) * sin(ANGLE)) - nbr->node[i][j].z;
			// printf("x_iso[%d][%d] : %.3f\n" , i, j ,nbr->node[i][j].x);
			// printf("y_iso[%d][%d] : %.3f\n" , i, j ,nbr->node[i][j].y);
			// printf("bf [%d][%d] :[%.3f][%.3f]\n" , i, j ,nbr->node[i][j].x, nbr->node[i][j].y);
			// printf("start\n");
			// my_mlx_pixel_put(&crt->img, (int)(nbr->node[i][j].x ), (int)(nbr->node[i][j].y) , nbr->node[i][j].color);

			j++;
		}
		// printf("\n");
		i++;
	}
	// exit(0);
}

float	ft_isomap(float x_map, float y_map , char axis)
{
	if (axis == 'x')
		return ((x_map - y_map) * cos(ANGLE));
	if (axis == 'y')
		return ((x_map + y_map) * sin(ANGLE));
	return(0);
}


void	ft_setcenter(t_fillnbr *nbr, t_keyhook *crt)
{
	float	x_map;
	float	y_map;
	float	x_cen;
	float	y_cen;
	int		i;
	int		j;

	(void)crt;

	i = 0;
	j = 0;

    // x_move =  ((float)WIN_WIDTH_CEN) - (nbr->col / 2 * nbr->ratio);
	// y_move =  ((float)WIN_HEIGHT_CEN) - (nbr->row / 2 * nbr->ratio);
    x_map =  nbr->col / 2 * nbr->ratio;
	y_map =  nbr->row / 2 * nbr->ratio;
	x_cen = (float)WIN_WIDTH_CEN - (ft_isomap(x_map, y_map, 'x'));
	y_cen = (float)WIN_HEIGHT_CEN - (ft_isomap(x_map, y_map, 'y'));
	while (i < nbr->col)
	{
		j = 0;
		while (j < nbr->row)
		{
			// iso_xyz()
			nbr->node[i][j].x = nbr->node[i][j].x + x_cen; 
			nbr->node[i][j].y = nbr->node[i][j].y + y_cen; 
			// printf("x_cen[%d][%d] :%.3f\n" , i, j ,nbr->node[i][j].x);
			// printf("y_cen[%d][%d] :%.3f\n" , i, j ,nbr->node[i][j].y);
			// exit(0);
			// my_mlx_pixel_put(&crt->img, (int)(nbr->node[i][j].x), (int)(nbr->node[i][j].y), WHITE_CL); //put point
			j++;
		}
		i++;
	}
	// exit(0);
}


void	ft_resetdata(t_fillnbr *nbr, t_point *value , t_keyhook *data)
{
	(void)value;
	ft_setratio(nbr);
	ft_setcenter(nbr, data);
	// int	i= 0;
	// while (i < nbr->col)
	// {
	// 	int j = 0;
	// 	while (j < nbr->row)
	// 	{
	// 		// printf("bf [%d][%d] :[%.3f][%.3f]\n" , i, j ,nbr->node[i][j].x, nbr->node[i][j].y);
	// 		j++;
	// 	}
	// 	i++;
	// }
	ft_isometric(nbr ,data);
	// exit(0);
	
}

void    ft_create(t_fillnbr *nbr, t_keyhook *data)
{
	ft_resetdata(nbr, *nbr->node , data);
	// ft_isometric(nbr, data);
	ft_createline(nbr, data);

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