/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:07:10 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/09 21:12:10 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include"libft/libft.h"
# include"get_next_line/get_next_line.h"
# include "mlx.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<math.h>


// typedef struct s_list
// {

// } t_
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_list
{
	int				i;
	int				x;
	int				y;
	int				fd;
	float			row;
	float			*col;
	char			**nbr;
	char			*tmp;
	char			**line;
	int				**res_int; // nbr
	char			**res;
	float			**arr_x;
	float			**arr_y;
	// struct s_list	*next;
}	t_fillnbr;

# define CANNT_OPEN 1

# define ANGLE 0.523599 // 30 degree
# define ANGLE2 1.0472 // 60 degree

# define WHITE_CL 0xFFFFFF

//putnbr
int		ft_cntline(char *av);
char	**ft_split_line(int row, char *av);
// void	ft_fillnum(int **res_int, char **line, int *col ,int row);
void	ft_fillnum(int **res_int, char **line, float *col, float row);

//checkerr
void	ft_printerr(int mode);
void	ft_checkarg(int ac);

//crete line
void	ft_creteline(float x1, float y1, float x2, float y2);
void	ft_dda(float x1, float y1, float x2, float y2);

//crete shape
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_crtrectangle(float row, float *col, t_data img);
void	ft_crtpoint_middle(t_fillnbr *nbr, t_data *img);


float	**ft_crtarr_x(t_fillnbr *nbr);
float	**ft_crtarr_y(t_fillnbr *nbr);
void	ft_isometric(t_fillnbr *nbr, t_data *img);


#endif
