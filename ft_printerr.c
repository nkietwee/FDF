/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:49:04 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/19 22:27:15 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_printerr(int mode)
{
	if (mode == 1)
		ft_putstr_fd("It cannot open file\n", 2);
	else if (mode == 2)
		ft_putstr_fd("Error\n", 2);
	else if (mode == 3)
		ft_putstr_fd("Check arg\n", 2);
	exit(0);
}

void	ft_checkfd(int fd)
{
	if (fd == -1)
		ft_printerr(CANNT_OPEN);
}
