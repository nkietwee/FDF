/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:16:12 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/19 22:37:22 by nkietwee         ###   ########.fr       */
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

long	ft_htoi(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = i + 2;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			res = (16 * res) + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
				res = (16 * res) + (str[i] - 'a' + 10);
		else if (str[i] >= '0' && str[i] <= '9')
			res = (16 * res) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_setratio(t_fillnbr *nbr)
{
	float	i;

	i = 0;
	while (i < WIN_WIDTH / (((nbr->row + nbr->col)) * cos(ANGLE)) * MAGIC)
		i++;
	nbr->ratio = i;
}
