/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/19 13:50:33 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_checkcol(t_fillnbr *nbr, int check)
{
	if (nbr->z_2d[nbr->col - 1][0] == '\n')
		ft_printerr(ER_MAP);
	if (check != nbr->col)
		ft_printerr(ER_MAP);
}

void	ft_countcol(t_fillnbr *nbr, char *av)
{
	nbr->i = 0;
	nbr->pv = 0;
	nbr->fd = open(av, O_RDONLY);
	ft_checkfd(nbr->fd);
	nbr->line_col = (char **)malloc(sizeof(char *) * (nbr->row + 1));
	if (!nbr->line_col)
		return ;
	while (nbr->i < nbr->row)
	{
		nbr->line_col[nbr->i] = get_next_line(nbr->fd);
		if (!nbr->line_col[nbr->i])
			break ;
		nbr->line_col[nbr->i + 1] = 0;
		nbr->z_2d = ft_split(nbr->line_col[nbr->i], ' ');
		nbr->col = 0;
		while (nbr->z_2d[nbr->col])
			nbr->col++;
		if (nbr->i == 0)
			nbr->check = nbr->col;
		ft_checkcol(nbr, nbr->check);
		ft_free2d(nbr->z_2d);
		nbr->i++;
	}
	ft_free2d(nbr->line_col);
	close(nbr->fd);
}

void	ft_countrow(t_fillnbr *nbr, char *av)
{
	int	fd;

	fd = 0;
	nbr->line_row = NULL;
	nbr->row = 0;
	fd = open(av, O_RDONLY);
	ft_checkfd(fd);
	while (1)
	{
		nbr->line_row = get_next_line(fd);
		if (!nbr->line_row)
			break ;
		free(nbr->line_row);
		nbr->row++;
	}
	if (nbr->row == 0)
		ft_printerr(ER_MAP);
	close(fd);
}

void	ft_count(t_fillnbr *nbr, char *av)
{
	ft_countrow(nbr, av);
	ft_countcol(nbr, av);
}
