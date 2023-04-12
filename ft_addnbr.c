/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:44 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/12 19:03:31 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//allocate meemory
void	ft_allocate(t_fillnbr *nbr)
{
	// printf("row : %d\n", nbr->row);
	// printf("col : %d\n", nbr->col);
	// int	i;

	// i = 0;
	nbr->i = 0;
	nbr->node = (t_point **)malloc(sizeof(t_point *) * (nbr->row));
	if (!nbr->node)
		return ;
	// while (i < nbr->row)
	while (nbr->i < nbr->row)
	{
		// nbr->node[i] = (t_point *)malloc(sizeof(t_point ) * (nbr->col));
		nbr->node[nbr->i] = (t_point *)malloc(sizeof(t_point ) * (nbr->col));
		if (!nbr->node[nbr->i])
			return ;
		nbr->i++;
	}
	// printf("hello from allocate\n");
}

//add value to arr_x(and arr_y if you open comment)
void	ft_addarr_x(t_fillnbr *nbr)
{
	int	num_x;
	// int	num_y;

	nbr->i = 0;
	num_x = 0;
	// printf("column : %d\n" , nbr->col);
	// exit(0);
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		// num_y = 0;
		while(nbr->j < nbr->col)
		{
			nbr->node[nbr->i][nbr->j].x = num_x; // why use point
			// nbr->node[nbr->i][nbr->j].y = num_y; // why use point
			// printf("i : %d, j : %d, num_x : %d\n", nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].x);
			// printf("i : %d, j : %d, num_y : %d\n", nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].y);
			// num_y++;
			nbr->j++;
		}
		num_x++;
		nbr->i++;
	}
}

void	ft_addarr_y(t_fillnbr *nbr)
{
	int	num_y;
	int	fd;

	nbr->i = 0;
	nbr->j = 0;
	fd = 0;
	num_y = 0;
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		num_y = 0;
		while(nbr->j < nbr->col)
		{
			nbr->node[nbr->i][nbr->j].y = num_y; // why use point
			// printf("i : %d, j : %d, num_y : %d\n", nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].y);
			num_y++;
			nbr->j++;
		}
		nbr->i++;
	}
}
void	ft_addarr_z(t_fillnbr *nbr, char *av)
{
	int	fd;

	nbr->i = 0;
	nbr->j = 0;
	nbr->t = 0;
	fd = open(av, O_RDONLY);
	// printf("hello\n");
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		while(nbr->j < nbr->col)
		{
			nbr->line_z = get_next_line(fd);
			if (!nbr->line_z)
				break ;//return (0);
			nbr->z_2d = ft_split(nbr->line_z, ' ');
			nbr->t = 0;
			nbr->j = 0;
			while(nbr->z_2d[nbr->t])
			{	
				nbr->node[nbr->i][nbr->j].z = ft_atoi(nbr->z_2d[nbr->t]); // why use point
				// printf("nbr[%d][%d] : %d\n" , nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].z);
				nbr->t++;
				nbr->j++;
			}
			// printf("\n");
		}
		nbr->i++;
	}
	close(fd);
	// exit(0);

}

void	ft_addnbr(t_fillnbr *nbr, char *av)
{
	(void)av;
	ft_allocate(nbr);
	ft_addarr_x(nbr);
	ft_addarr_y(nbr);
	ft_addarr_z(nbr, av);

}

//draft add arr_x arr_y
// //add value to arr_x(and arr_y if you open comment)
// void	ft_addarr_x(t_fillnbr *nbr)
// {
// 	int	num_x;
// 	// int	num_y;

// 	nbr->i = 0;
// 	nbr->j = 0;
// 	num_x = 0;
// 	nbr->node = (t_point **)malloc(sizeof(t_point *) * (nbr->row));
// 	if (!nbr->node)
// 		return ;
// 	while (nbr->i < nbr->row)
// 	{
// 		nbr->node[nbr->i] = (t_point *)malloc(sizeof(t_point ) * (nbr->col));
// 		if (!nbr->node[nbr->i])
// 			return ;
// 		nbr->j = 0;
// 		// num_y = 0;
// 		while(nbr->j < nbr->col)
// 		{
// 			nbr->node[nbr->i][nbr->j].x = num_x; // why use point
// 			// nbr->node[nbr->i][nbr->j].y = num_y; // why use point
// 			// printf("i : %d, j : %d, num_x : %d\n", nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].x);
// 			// printf("i : %d, j : %d, num_y : %d\n", nbr->i, nbr->j, nbr->node[nbr->i][nbr->j].y);
// 			// num_y++;
// 			nbr->j++;
// 		}
// 		num_x++;
// 		nbr->i++;
// 	}
// }