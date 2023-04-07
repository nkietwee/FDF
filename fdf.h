/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:07:10 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/08 01:47:21 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include"libft/libft.h"
# include"get_next_line/get_next_line.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_list
{
	int				i;
	int				x;
	int				y;
	int				fd;
	int				row;
	int				*col;
	char			**nbr;
	char			*tmp;
	char			**line;
	int				**res_int; // nbr
	char			**res;

	struct s_list	*next;
}	t_fillnbr;

# define CANNT_OPEN 1

int		ft_cntline(char *av);
char	**ft_split_line(int row, char *av);
void	ft_fillnum(int **res_int, char **line, int *col ,int row);

void	ft_printerr(int mode);
void	ft_checkarg(int ac);
#endif
