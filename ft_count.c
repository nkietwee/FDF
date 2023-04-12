/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/12 18:37:51 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_countcol(t_fillnbr *nbr, char *av)
{
	int	i;
	int pv;
	int	fd;

	i = 0;
	fd = 0;
	pv = 0;
	fd = open(av , O_RDONLY);
	nbr->col = 0;
	// printf("Hello\n");
	nbr->line_col = (char **)malloc(sizeof(char * ) * nbr->row);
	if (!nbr->line_col)
		return ;
	while (1)
	{
		nbr->line_col[i] = get_next_line(fd);
		if (!nbr->line_col[i]) // can't read 
			break ; // break or exit
		nbr->z_2d = ft_split(nbr->line_col[i], ' '); // split colour
		while (nbr->z_2d[nbr->col])
		{
			// exit(0);
			nbr->col++;
		}
			// printf("Hello   World\n");
		// if (pv != nbr->col)  //chk amout of line
		// 	printf("error\n");
		// printf("%d , %d\n" , i, nbr->col);
		i++;
	}
	close(fd);
	// printf("col : %d\n" , nbr->col);
	// exit(0);

}

void	ft_countrow(t_fillnbr *nbr, char *av)
{
	int	fd;

	fd = 0;
	nbr->line_row = NULL;
	nbr->row = 0;

	fd = open(av, O_RDONLY);
	// printf ("fd : %d\n" , fd);
	while (1)
	{
		nbr->line_row = get_next_line(fd); // don't forgot split colour
		// printf("line : %s\n" ,nbr->line);
		if (!nbr->line_row)
			break;
		nbr->row++;
	}
	// printf("%d\n" , nbr->row);
	close(fd);
}

void	ft_count(t_fillnbr *nbr, char *av)
{
	ft_countrow(nbr, av);
	ft_countcol(nbr, av);
}
