/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:41:25 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 01:08:52 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_free2d(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free (str[i]);
        i++;
    }
    free (str);
}

void    ft_freestruct2d(t_point **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free (str[i]);
        i++;
    }
    free (str);
}