/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:16:12 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/16 20:35:15 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_cnvdegreetoradian(float degree)
{
	float radian;

	radian = (degree / 180 ) * PI;
	return (radian);
}

long    ft_htoi(char *str)
{
    int     i;
    long    res;

    i = 0;
    res = 0;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        i = i + 2;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'f')
            res = (16 * res) + (str[i] - 'a' + 10);
        else if (str[i] >= 'A' && str[i] <= 'F')
            res = (16 * res) + (str[i] - 'a' + 10);
        else if (str[i] >= '0' && str[i] <= '9')
            res = (16 * res) + (str[i] - '0');
        i++;
    }
    return(res);
}
