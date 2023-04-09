/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:44:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/09 0:51 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(int ac, char **av)
{
	t_fillnbr nbr;

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init(); //connection to the correct graphical system
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); // create window
	img.img = mlx_new_image(mlx, 1920, 1080); //create
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian); // put 0,0 first point


	ft_checkarg(ac);
	nbr.row = ft_cntline(av[1]);
	nbr.line = ft_split_line(nbr.row, av[1]);
	nbr.res_int = (int **)malloc(sizeof(int *) * nbr.row);
	ft_fillnum(nbr.res_int, nbr.line, nbr.col, nbr.row);
	// ft_crtrectangle(nbr.row, nbr.col, img);
	// ft_crtpoint_middle(&nbr, &img);


	float **arr_x = ft_crtarr_x(&nbr);
	arr_x = 0;
	float **arr_y = ft_crtarr_y(&nbr);
	arr_y = 0;
	ft_isometric(&nbr, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // put pic to window
	mlx_loop(mlx); // loop window

	//// try drawline
	// float x1 = 1.0000;
	// float y1 = 1.0000;
	// float x2 = 8.0000;
	// float y2 = 5.0000;
	// // ft_creteline(x1, y1, x2, y2);
	// ft_dda(x1, y1, x2, y2);

	exit(0);
}
