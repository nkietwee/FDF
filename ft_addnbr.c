/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:44 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 00:26:37 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_allocate(t_fillnbr *nbr)
{
	int	i;

	i = 0;
	nbr->node = (t_point **)malloc(sizeof(t_point *) * (nbr->col));
	if (!nbr->node)
		return ;
	while (i < nbr->col)
	{
		nbr->node[i] = (t_point *)malloc(sizeof(t_point) * (nbr->row));
		if (!nbr->node[i])
			return ;
		i++;
	}
}

void	ft_addarr_x(t_fillnbr *nbr)
{
	int	num_x;
	int	i;
	int	j;

	j = 0;
	num_x = 0;
	while (j < nbr->row)
	{
		i = 0;
		num_x = 0;
		while (i < nbr->col)
		{
			nbr->node[i][j].x = num_x * nbr->ratio;
			num_x++;
			i++;
		}
		j++;
	}
}

void	ft_addarr_y(t_fillnbr *nbr)
{
	int	num_y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	num_y = 0;
	while (i < nbr->col)
	{
		j = 0;
		num_y = 0;
		while (j < nbr->row)
		{
			nbr->node[i][j].y = num_y * nbr->ratio;
			j++;
			num_y++;
		}
		i++;
	}
}

// void	ft_addcolor(t_fillnbr *nbr)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (z > 0)
// 	{
// 		while (i < )
// 	}
// 	else
// 		nbr->node[i][j].color =	(long)BLUE_CL;
// 	// while (i < nbr->col)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < y)
// 	// 	{
// 	// 		nbr->node[i][j].color =  
			
// 	// 	}
		
// 	// }
	
// }

void	ft_addvalue(t_fillnbr *nbr, int fd)
{
	nbr->line_z = get_next_line(fd);
	if (!nbr->line_z)
		return ;
	nbr->z_2d = ft_split(nbr->line_z, ' ');
	nbr->t = 0;
	nbr->i = 0;
	while (nbr->z_2d[nbr->t])
	{	
		nbr->z_val = ft_split(nbr->z_2d[nbr->t], ',');
		nbr->node[nbr->i][nbr->j].z = ft_atoi(nbr->z_val[0]) * nbr->ratio * MAGIC_Z;
		if (nbr->z_val[1])
			nbr->node[nbr->i][nbr->j].color = ft_htoi(nbr->z_val[1]);
		else
			nbr->node[nbr->i][nbr->j].color = (long)(BLUE_CL);
		nbr->t++;
		nbr->i++;
	}
	free(nbr->line_z);
	ft_free2d(nbr->z_val);
	ft_free2d(nbr->z_2d);
}

void	ft_addarr_z(t_fillnbr *nbr, char *av)
{
	int	fd;
	int	cl;

	cl = 0;
	nbr->i = 0;
	nbr->j = 0;
	nbr->t = 0;
	fd = open(av, O_RDONLY);
	while (nbr->j < nbr->row)
	{
		nbr->i = 0;
		while (nbr->i < nbr->col)
			ft_addvalue(nbr, fd);
		nbr->j++;
	}
	close(fd);
}

void	ft_addnbr(t_fillnbr *nbr, char *av)
{
	ft_setratio(nbr);
	ft_allocate(nbr);
	ft_addarr_x(nbr);
	ft_addarr_y(nbr);
	ft_addarr_z(nbr, av);
}
