/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:56:30 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/16 21:36:26 by nkietwee         ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_WIDTH_CEN 960
# define WIN_HEIGHT_CEN 540


# define MAGIC 0.3 //edit
# define MAGIC_Z 0.1

# define CANNT_OPEN 1

# define PI M_PI
// # define ANGLE 0.8 // 45 degree
# define ANGLE 0.523599 // 30 degree
# define ANGLE2 1.0472 // 60 degree
# define VAL_30 1.1547 // 30 degree

# define WHITE_CL 0xFFFFFF
# define BLUE_CL 0xFFFFF
# define YEL_CL 0xFFBF00
# define GREEN_CL 0x00fa43
# define PINK_CL 0xfa00c0

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
	float	x;
	float	y;
	float	z;
	long	color;
} t_point;

typedef	struct	s_data4
{
	// char	**av;
	int		row;
	int		col;
	int		ratio; //  distance between point
	int		i; //index for keep arr2d
	int		j; //index for keep arr2d
	int		t; //loop split
	char	*line_row; //count col
	char	**line_col; //receive value from av
	char	*line_z; // split for value z
	char	**z_2d; // split for count col
	char	**z_val; // split for color
	t_point **node;
}	t_fillnbr;

//cf
void	ft_checkmap(int ac);
void	ft_chkarg(int ac);

//count and fill
void	ft_count(t_fillnbr *nbr, char *av);
void	ft_countrow(t_fillnbr *nbr, char *av);

// fill nbr
void	ft_addnbr(t_fillnbr *nbr, char *av);
void	ft_addarr_x(t_fillnbr *nbr);
void	ft_addarr_y(t_fillnbr *nbr);
void	ft_addarr_z(t_fillnbr *nbr, char *av);


//crt
void    ft_create(t_fillnbr *nbr, t_keyhook *data);
void	ft_setratio(t_fillnbr *nbr);
void	ft_setcenter(t_fillnbr *nbr, t_keyhook *data);
// void	ft_setcenter(t_fillnbr *nbr);

float	ft_abs(float num);
void	ft_dda(t_point *start, t_point *end, t_keyhook *crt);
// void	ft_isometric(t_fillnbr *nbr);
void	ft_isometric(t_fillnbr *nbr , t_keyhook *crt);
void	ft_crtrectangle(int row, int col, t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
long    ft_htoi(char *str);

#endif
