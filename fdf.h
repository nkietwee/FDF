/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:56:30 by nkietwee          #+#    #+#             */
/*   Updated: 2023/05/27 14:04:39 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_WIDTH_CEN 960
# define WIN_HEIGHT_CEN 540
# define MAGIC 0.5
# define MAGIC_Z 0.1
# define CANNT_OPEN 1
# define ER_MAP 2
# define CHK_ARG 2
# define PI M_PI
# define ANGLE 0.523599
# define ANGLE2 1.0472
# define VAL_30 1.1547
# define WHITE_CL 0xFFFFFF
# define BLUE_CL 0xFFFFF
# define YEL_CL 0xFFBF00
# define GREEN_CL 0x00fa43
# define PINK_CL 0xfa00c0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_keyhook
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_keyhook;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	long	color;
}	t_point;

typedef struct s_fillnbr
{
	int			row;
	int			col;
	int			ratio;
	int			i;
	int			j;
	int			t;
	int			pv;
	int			fd;
	int			check;
	char		*line_row;
	char		**line_col;
	char		*line_z;
	char		**z_2d;
	char		**z_val;
	t_point		**node;
	t_keyhook	display;
}	t_fillnbr;

typedef struct s_drawline
{
	float	dx;
	float	dy;
	float	step;
	float	x_incre;
	float	y_incre;
	float	i;
	float	tmp_start_x;
	float	tmp_start_y;
}	t_drawline;

// cf
void	ft_check(int ac, char **av);
void	ft_checkarg(int ac);
void	ft_checkextension(char *av);

// count and fill
void	ft_count(t_fillnbr *nbr, char *av);
void	ft_countrow(t_fillnbr *nbr, char *av);
void	ft_countcol(t_fillnbr *nbr, char *av);
void	ft_checkcol(t_fillnbr *nbr, int check);

// fill nbr
void	ft_addnbr(t_fillnbr *nbr, char *av);
void	ft_allocate(t_fillnbr *nbr);
void	ft_addarr_x(t_fillnbr *nbr);
void	ft_addarr_y(t_fillnbr *nbr);
void	ft_addarr_z(t_fillnbr *nbr, char *av);
void	ft_addvalue(t_fillnbr *nbr);
long	ft_htoi(char *str);

void	ft_free2d(char **str);
void	ft_freestruct2d(t_point **str);

int		ft_closewin(t_fillnbr *param);
int		ft_key_hook(int keycode, t_fillnbr *param);

// crt
void	ft_create(t_fillnbr *nbr, t_keyhook *data);
void	ft_setratio(t_fillnbr *nbr);
void	ft_setcenter(t_fillnbr *nbr);

void	ft_createline(t_fillnbr *nbr, t_keyhook *img);
void	ft_dda(t_point *start, t_point *end, t_keyhook *crt);
float	ft_findmax(float dx, float dy);
float	ft_abs(float num);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_isometric(t_fillnbr *nbr);

void	ft_printerr(int mode);
void	ft_checkfd(int fd);
#endif
