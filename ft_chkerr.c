/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:43 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 21:42:31 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_checkextension(char *av)
{
	int	len;

	if (!av)
		return ;
	len = ft_strlen(av);
	if (len > 4)
	{
		if (av[len - 1] == 'f' && av[len - 2] == 'd' \
		&& av[len - 3] == 'f' && av[len - 4] == '.')
		{
			return ;
		}
	}
	ft_printerr(ER_MAP);
}

void	ft_checkarg(int ac)
{
	if (ac != 2)
		ft_printerr(CHK_ARG);
}

void	ft_check(int ac, char **av)
{
	ft_checkarg(ac);
	ft_checkextension(av[1]);
}
