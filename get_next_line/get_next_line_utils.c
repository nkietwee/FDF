/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:07:18 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/07 15:41:33 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoinfree(char *dst, char *src)
{
	int		i;
	int		dstlen;
	int		srclen;
	char	*ans;

	i = 0;
	dstlen = my_ft_strlen(dst, 0);
	srclen = my_ft_strlen(src, 0);
	ans = (char *)malloc(sizeof(char) * (dstlen + srclen + 1));
	while (dst[i] != '\0')
	{
		ans[i] = dst[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		ans[dstlen + i] = src[i];
		i++;
	}
	ans[dstlen + i] = '\0';
	free(dst);
	return (ans);
}
