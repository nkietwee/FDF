/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:43 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/17 15:02:33 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_ft_checkextension
void	ft_checkarg(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("check argument\n", 2);
		exit(1);
	}

}
void	ft_checkmap(int ac)
{
	ft_checkarg(ac);
	ft_checkextension();
	//ft_chkalphabet
}
