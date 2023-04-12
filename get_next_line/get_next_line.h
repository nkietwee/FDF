/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:36 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/07 13:56:49 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		find_n(char *str);
int		my_ft_strlen(char *str, int mode);
char	*get_next_line(int fd);
char	*ft_keeptmp(char *tmp);
char	*ft_keeptext(char *tmp);
char	*ft_readbufjoin(char *tmp, int fd, int readbuf);
char	*ft_strjoinfree(char *dst, char *src);

#endif
