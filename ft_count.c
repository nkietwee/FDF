/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 02:22:36 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_checkcol(t_fillnbr *nbr, int check)
{
	if (nbr->z_2d[nbr->col - 1][0] == '\n')
	{
		printf("Error");
		exit(0);
	}		
	if (check != nbr->col)
	{
		printf("line is not equal");
		exit(0);
	}
}

void	ft_countcol(t_fillnbr *nbr, char *av)
{
	nbr->i = 0;
	nbr->pv = 0;
	nbr->fd = open(av, O_RDONLY);
	nbr->line_col = (char **)malloc(sizeof(char *) * nbr->row);
	if (!nbr->line_col)
		return ;
	while (nbr->i < nbr->row)
	{
		nbr->line_col[nbr->i] = get_next_line(nbr->fd);
		if (!nbr->line_col[nbr->i])
			break ;
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
	while (1)
	{
		nbr->line_row = get_next_line(fd);
		if (!nbr->line_row)
			break ;
		free(nbr->line_row);
		nbr->row++;
	}
	if (nbr->row == 0)
	{
		printf("blank file");
		exit(0);
	}
	close(fd);
}

void	ft_count(t_fillnbr *nbr, char *av)
{
	ft_countrow(nbr, av);
	ft_countcol(nbr, av);
}
