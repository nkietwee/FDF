/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:57:43 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/11 15:04:33 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"


void	ft_chkarg(int ac)
{
	if (ac == 1)
	{
		ft_putstr_fd("checkarg\n", 2);
		exit(0);
	}

}
void	ft_checkmap(int ac)
{
	ft_chkarg(ac);
	// ft_chkfileextension
	//ft_chkalphabet
}
