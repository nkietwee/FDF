/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:04:24 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/19 23:57:12 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static	void	ft_printerror(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	exit(0);
}
static	void	ft_checkbfatoi(char c)
{
	if (ft_isdigit(c) == 0 && c != '\0' && c != '\n')
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}	
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sym;	
	long	res;

	i = 0;
	sym = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sym = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((res > 2147483647 && sym == 1) || (res > 2147483648 && sym == -1))
			ft_printerror("Error\n", 2);
		i++;
	}
	ft_checkbfatoi(str[i]);
	return (res * sym);
}
