/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:44:15 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/08 14:21:18 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	main(int ac, char **av)
{
	t_fillnbr nbr;

	ft_checkarg(ac);
	nbr.row = ft_cntline(av[1]);
	nbr.line = ft_split_line(nbr.row, av[1]);
	nbr.res_int = (int **)malloc(sizeof(int *) * nbr.row);
	ft_fillnum(nbr.res_int, nbr.line, nbr.col, nbr.row);
	printf("main %d\n" , (*nbr.col));
	exit(0);
}
