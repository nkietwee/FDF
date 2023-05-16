/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/16 12:26:39 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_keyhook display;
	t_fillnbr nbr;

	(void)nbr;
	(void)ac;
	(void)av;

	display.mlx = mlx_init(); //connection to the correct graphical system
	display.mlx_win = mlx_new_window(display.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!"); // create window
	display.img.img = mlx_new_image(display.mlx, WIN_WIDTH, WIN_HEIGHT); //create image
	display.img.addr = mlx_get_data_addr(display.img.img, &display.img.bits_per_pixel, &display.img.line_length,
								&display.img.endian); // put 0,0 first point

	ft_checkmap(ac);
	ft_count(&nbr, av[1]);
	ft_addnbr(&nbr, av[1]);
	ft_create(&nbr, &display);
	my_mlx_pixel_put(&display.img, 10, 10 , WHITE_CL); //put point
	
	mlx_put_image_to_window(display.mlx, display.mlx_win, display.img.img, 0, 0); // put pic to window
	mlx_loop(display.mlx); // loop window

}
