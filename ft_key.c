/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:40:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/22 00:41:51 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_closewin(t_fillnbr *param)
{
	mlx_destroy_window(param->display.mlx, param->display.mlx_win);
	exit (0);
	return (0);
}

int	ft_key_hook(int keycode, t_fillnbr *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->display.mlx, param->display.mlx_win);
		exit (0);
	}
	return (0);
}
