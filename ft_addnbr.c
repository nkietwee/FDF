/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:44 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/22 00:48:04 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_addvalue(t_fillnbr *nbr)
{
	int	t;

	while (nbr->z_2d[nbr->t])
	{	
		nbr->z_val = ft_split(nbr->z_2d[nbr->t], ',' );
		t = 0;
		while (nbr->z_val[t])
			t++;
		if (t == 1 || t == 2)
		{
			nbr->node[nbr->i][nbr->j].z = ft_atoi(nbr->z_val[0]) \
				* nbr->ratio * MAGIC_Z;
			if (nbr->z_val[1])
				nbr->node[nbr->i][nbr->j].color = ft_htoi(nbr->z_val[1]);
			else if (nbr->z_val[0])
				nbr->node[nbr->i][nbr->j].color = (long)(BLUE_CL);
		}
		else
			ft_printerr(ER_MAP);
		nbr->t++;
		nbr->i++;
		ft_free2d(nbr->z_val);
	}
}

void	ft_addarr_z(t_fillnbr *nbr, char *av)
{
	int	fd;

	nbr->i = 0;
	nbr->j = 0;
	nbr->t = 0;
	fd = open(av, O_RDONLY);
	ft_checkfd(fd);
	while (nbr->j < nbr->row)
	{
		nbr->i = 0;
		while (nbr->i < nbr->col)
		{
			nbr->line_z = get_next_line(fd);
			if (!nbr->line_z)
				return ;
			nbr->z_2d = ft_split(nbr->line_z, ' ');
			nbr->t = 0;
			nbr->i = 0;
			ft_addvalue(nbr);
			ft_free2d(nbr->z_2d);
			free(nbr->line_z);
		}
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
