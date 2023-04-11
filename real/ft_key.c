/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:40:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/10 16:49:52 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	ft_closewindow(int keycode, t_keyhook *param)
{
	(void)param;
	printf("keycode %d\n" ,keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		exit (0);
	}
	return (0);

}
