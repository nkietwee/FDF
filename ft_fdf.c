/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:39:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/12 18:43:11 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	// t_keyhook display;
	t_fillnbr nbr;

	// display.mlx = mlx_init(); //connection to the correct graphical system
	// display.mlx_win = mlx_new_window(display.mlx, 1920, 1080, "Hello world!"); // create window
	// display.img.img = mlx_new_image(display.mlx, 1920, 1080); //create
	// display.img.addr = mlx_get_data_addr(display.img.img, &display.img.bits_per_pixel, &display.img.line_length,
	// 							&display.img.endian); // put 0,0 first point

	ft_checkmap(ac);
	ft_count(&nbr, av[1]);
	ft_addnbr(&nbr, av[1]);


	// ft_addarr_y(&nbr);
	// printf("row : %d\n",nbr.row);
	// printf("col : %d\n",nbr.col);
	// exit(0);



	// mlx_put_image_to_window(display.mlx, display.mlx_win, display.img.img, 0, 0); // put pic to window
	// mlx_loop(display.mlx); // loop window

}
