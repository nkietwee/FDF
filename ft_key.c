/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:40:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/17 22:34:49 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	ft_closewin(int keycode, t_keyhook *param)
int	ft_closewin(t_fillnbr *param)
{
	// int keycode = 53;
	// (void)param;
	// printf("----keycode %d\n" ,keycode);
	// if (keycode == 53) // click close
	// {
	mlx_destroy_image(param->display.mlx, &param->display.img);
	mlx_destroy_window(param->display.mlx, param->display.mlx_win);
	ft_freestruct2d(param->node);
	exit(0);
		
	return (0);

}

// int	ft_key_hook(int keycode, t_keyhook *param)
int	ft_key_hook(int keycode, t_fillnbr *param)
{
	printf("keycode : %d\n" ,keycode);
	if (keycode == 53) // click close
	{
		printf("ESC\n");
		mlx_destroy_image(param->display.mlx, &param->display.img);
		mlx_destroy_window(param->display.mlx, param->display.mlx_win);
		ft_freestruct2d(param->node);
		exit (0);
	}
	return(0);
}