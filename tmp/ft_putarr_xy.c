/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:49:12 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/09 23:50:13 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

float	**ft_crtarr_x(t_fillnbr *nbr)
{
	int i;
	int j;
	int num;

	i = 0;
	j = 0;
	num = 0;
	nbr->arr_x = (float **)malloc(sizeof(float * ) * nbr->row);
	if (!nbr->arr_x)
		return (0);
	while(i < nbr->row)
	{
		nbr->arr_x[i] = malloc(sizeof(float) * (*(nbr->col)));
		if (!nbr->arr_x[i])
			return (0);
		j = 0;
		num = 0;
		while(j < (*(nbr->col)))
		{
			nbr->arr_x[i][j] = num;
			// printf("arr[%d][%d] : %f\n", i ,j, nbr->arr_x[i][j]);
			// printf("%d ", (int)nbr->arr_x[i][j]);
			j++;
			num++;
		}
		// printf("\n------------------\n");
		// printf("\n");
		i++;
	}
	return(nbr->arr_x);


}


float	**ft_crtarr_y(t_fillnbr *nbr)
{
	int	a;
	int	b;
	int num;

	a = 0;
	b = 0;
	num = 0;
	nbr->arr_y = (float **)malloc(sizeof(float * ) * (nbr->row));
	if (!nbr->arr_y)
		return (0);
	while(a < nbr->row)
	{
		nbr->arr_y[a] = malloc(sizeof(float) * (*(nbr->col)));
		if (!nbr->arr_y[a])
			return (0);
		b = 0;
		while(b < (*(nbr->col)))
		{
			nbr->arr_y[a][b] = num;
			// printf("          arr[%d][%d] : %f\n", a ,b, nbr->arr_y[a][b]);
			// printf("%f ", nbr->arr_y[a][b]);
			// printf("%d ", (int)nbr->arr_y[a][b]);
			b++;
		}
		// printf("\n--------------------\n");
		a++;
		num++;
	}
	return(nbr->arr_y);
}
