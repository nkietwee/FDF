/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:56:30 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/11 16:18:53 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include "key_mac.h"
# include <unistd.h> // write
# include <stdlib.h> // malloc
# include <stdio.h> // printf
# include <math.h> // sin cos tan

typedef struct	s_data1
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_data2
{
	void	*mlx;
	void	*mlx_win;
	// t_data	*img;
	t_data	img;
} t_keyhook;

typedef struct	s_data3
{
	int	x;
	int	y;
	int	z;
	// int	colour;
} t_point;

typedef struct	s_data4
{
	// char	**av;
	int		row;
	int		col;
	char	*line_row; //count col
	char	**line_col; //receive value from av
	char	**z_2d; // split for count col
	t_point **node;
} t_fillnbr;

void	ft_checkmap(int ac);

//count and fill
void	ft_count(t_fillnbr *nbr, char *av);
void	ft_countrow(t_fillnbr *nbr, char *av);




# define CANNT_OPEN 1

# define PI 3.141592

# define ANGLE 0.523599 // 30 degree
# define ANGLE2 1.0472 // 60 degree

# define WHITE_CL 0xFFFFFF


#endif