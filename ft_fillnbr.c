/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:43:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/08 10:43:59 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

// void ft_countline(char *av, int *row)
int	ft_cntline(char *av)
{
	t_fillnbr	cnt_row;

	cnt_row.fd = open(av, O_RDONLY);
	cnt_row.row = 0;
	if (cnt_row.fd == -1)
	{
		ft_printerr(CANNT_OPEN);
		exit (0);
	}
	while (1)
	{
		cnt_row.tmp = get_next_line(cnt_row.fd);
		if (!cnt_row.tmp)
			break;
		cnt_row.row++;
	}
	close(cnt_row.fd);
	return (cnt_row.row);
}

char	**ft_split_line(int row, char *av)
{
	t_fillnbr sp_row;

	sp_row.i = 0;
	sp_row.line = (char **)malloc(sizeof(char *) * (row));
	if (!sp_row.line)
		return(0);
	sp_row.fd = open(av, O_RDONLY);
	if (sp_row.fd == -1)
		return(0);
	while (1)
	{
		sp_row.line[sp_row.i] = get_next_line(sp_row.fd);
		if (!sp_row.line[sp_row.i])
			break;
		sp_row.i++;
	}
	return(sp_row.line);
}

void	ft_fillnum(int **res_int, char **line, int *col,int row)
{
	t_fillnbr fill;
	int a;
	int	count;
	(void)col;

	fill.i = 0;
	fill.x = 0;
	fill.res = (char **)malloc(sizeof(char *) * row);
	if (!fill.res)
		return ;
	while (line[fill.i])
	{
		// fill.i = 2;
		fill.res = ft_split(line[fill.i], ' ');  // str each row
		count = 0;
		while (fill.res[count])
			count++;
		*col = count;
		// printf("col : %d\n", *col);
		// printf("count : %d\n", count);
		// exit(0);
		res_int[fill.i] = (int *)malloc(sizeof(int) * (count));
		if (!res_int[fill.i])
			return;
		fill.y = 0;
		a = 0;
		while(fill.x < row && fill.y < count)
		{
			if (!fill.res[a])
				break;
			res_int[fill.x][fill.y] = ft_atoi(fill.res[a]);
			// printf("[%d][%d] : %d " ,x ,y ,res_int[x][y]);
			printf(" %d " ,res_int[fill.x][fill.y]);
			fill.y++;
			a++;
		}
		fill.x++;
		fill.i++;
		printf("\n");
	}
	// exit(0);
	// *col = count;
	// printf("rol\n");
	printf("inner col : %d\n", *col);
}
