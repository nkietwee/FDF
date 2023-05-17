/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 00:08:24 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_fillnbr nbr;

	ft_check(ac , av);
	nbr.display.mlx = mlx_init(); //connection to the correct graphical system
	nbr.display.mlx_win = mlx_new_window(nbr.display.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!"); // create window
	nbr.display.img.img = mlx_new_image(nbr.display.mlx, WIN_WIDTH, WIN_HEIGHT); //create image
	nbr.display.img.addr = mlx_get_data_addr(nbr.display.img.img, \
		&nbr.display.img.bits_per_pixel, &nbr.display.img.line_length,\
		&nbr.display.img.endian); // put 0,0 first point
	ft_count(&nbr, av[1]);
	ft_addnbr(&nbr, av[1]);
	ft_create(&nbr, &nbr.display);
	mlx_put_image_to_window(nbr.display.mlx, nbr.display.mlx_win, \
		nbr.display.img.img, 0, 0); // put pic to window
	mlx_hook(nbr.display.mlx_win, 2, 1L << 0, ft_key_hook, &nbr);
	mlx_hook(nbr.display.mlx_win, 17, 0, ft_closewin, &nbr);
	mlx_loop(nbr.display.mlx);
}
