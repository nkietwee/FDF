/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creteline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:23:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/08 23:11:22 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
float		ft_absf(float num)
{
	if (num < 0)
		return( -1.000000 * num );
	else
		return(num );
}

// DDA Algorithm
void	ft_dda(float x1, float y1, float x2, float y2)
{
	float x;
	float y;
	float delta_x;
	float delta_y;
	float round;
	float step;

	float x_increment;
	float y_increment;

	round = 0;
	x = x1;
	y = y1;
	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (ft_absf(delta_x) <  ft_absf(delta_y))
		step = ft_absf(delta_x);
	else
		step = ft_absf(delta_x);
	x_increment = delta_x  / step;
	y_increment = delta_y  / step;

	while (round <= step)
	{
		printf("x : %f , y : %f\n" ,x ,y); // put point at coorinate x y
		x = x + x_increment;
		y = y + y_increment;
		// printf("x : %f , y : %f\n" ,x ,y); // put point at coorinate x y
		// putpixel(Round(x), Round(y));
		round++;
	}

}


// Bresenham’s Line Generation
void	ft_creteline(float x1, float y1, float x2, float y2)
{
	float x;
	float y;
	float delta_x;
	float delta_y;
	float p;

	x = x1;
	y = y1;
	delta_x = x2 - x1;
	delta_y = y2 - y1;
	p = (2 * delta_y) - delta_x;
	// printf("x : %f \n", x);
	// printf("y : %f \n", y);
	// printf("delta_x : %f \n", delta_x);
	// printf("delta_y : %f \n", delta_y);
	// exit(0);
	while (x <= x2) // loop coordinate x( as x1) to x2
	{
		// printf("put x y\n"); // put point at coorinate x y
		printf("x : %f , y : %f\n" ,x ,y); // put point at coorinate x y
		x++; // x1
		if (p < 0)
		{
			p = p + (2 * delta_y);
			// printf("p in  : %f\n", p);
		}
		else
		{
			p = p + (2 * delta_y) - (2 * delta_x);
			// printf("p out : %f\n", p);
			y++;
		}
	}

}
