/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/11 01:09:18 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_countcol(t_fillnbr *nbr, char *av)
{
	int	i;
	int pv;
	int	fd;
	int	check;

	i = 0;
	fd = 0;
	pv = 0;
	fd = open(av, O_RDONLY);
	nbr->line_col = (char **)malloc(sizeof(char *) * nbr->row);
	if (!nbr->line_col)
		return ;
	while (1)
	{
		nbr->line_col[i] = get_next_line(fd);
		if (!nbr->line_col[i]) // can't read
			break ; // break or exit
		nbr->z_2d = ft_split(nbr->line_col[i], ' '); // left split colour
		nbr->col = 0;
		while (nbr->z_2d[nbr->col])
			nbr->col++;
		if (nbr->z_2d[nbr->col - 1][0] == '\n')
		{
			printf(" i %d, found \n", i);
			exit(0);
		}
		if (i == 0)
			check = nbr->col; 
		i++;
		if (check != nbr->col)
		{
			printf("line is not equal");
			exit(0);
		}
	}
	close(fd);
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
		nbr->line_row = get_next_line(fd); // don't forgot split colour
		// printf("line : %s" ,nbr->line_row);
		if (!nbr->line_row)
			break;
		nbr->row++;
	}
	// printf("%d\n" , nbr->row);
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
