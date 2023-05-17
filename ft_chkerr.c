/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:43 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/18 01:49:48 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_checkextension(char *av)
{
	int	len;

	if (!av)
		return (0);
	len = ft_strlen(av);
	if (len > 4) // ??
	{
		if (av[len - 1] == 'f' && av[len - 2] == 'd' \
		&& av[len - 3] == 'f' && av[len - 4] == '.')
		{
			return (0);
		}
	}
	printf("Error map\n");
	// exit ;
	return (-1);
}

int	ft_checkarg(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("checkarg\n", 2);
		return (-1);
	}
	return (0);
}

void	ft_check(int ac, char **av)
{
	if (ft_checkarg(ac) == -1)
		exit(0);
	if (ft_checkextension(av[1]) == -1)
		exit(0);
}
