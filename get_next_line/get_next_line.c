/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:22:23 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/07 14:14:00 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_ft_strlen(char *str, int mode)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (mode == 0)
	{
		while (str[i] != '\0')
			i++;
	}
	else if (mode == 1)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (i);
}

char	*ft_keeptmp(char *tmp)
{
	char	*kept;
	int		count_str;
	int		count_nl;
	int		i;

	if (!tmp || tmp[0] == 0)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	count_nl = my_ft_strlen(tmp, 1);
	count_str = my_ft_strlen(tmp, 0);
	kept = (char *)malloc(sizeof(char) * (count_str - count_nl + 1));
	if (!kept)
		return (NULL);
	while (i < count_str - count_nl)
	{
		kept[i] = tmp[i + count_nl];
		i++;
	}
	kept[i] = '\0';
	free (tmp);
	return (kept);
}

char	*ft_keeptext(char *tmp)
{
	char	*str;
	int		i;
	int		count_nl;

	i = 0;
	count_nl = my_ft_strlen(tmp, 1);
	if (tmp[0] == 0 || !tmp)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (count_nl + 1));
	if (!str)
		return (NULL);
	while (i < count_nl)
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_readbufjoin(char *tmp, int fd, int readbuf)
{
	char	*text;

	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (NULL);
	while (readbuf > 0)
	{
		readbuf = read(fd, text, BUFFER_SIZE);
		if (readbuf > 0)
		{
			text[readbuf] = '\0';
			tmp = ft_strjoinfree(tmp, text);
			if (find_n(tmp) == 1)
				break ;
		}
	}
	free(text);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*text;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, NULL, 0) == -1)
		return (NULL);
	if (!tmp)
	{
		tmp = (char *)malloc(sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
	}
	tmp = ft_readbufjoin(tmp, fd, 1);
	text = ft_keeptext(tmp);
	tmp = ft_keeptmp(tmp);
	return (text);
}

/*int	main(void)
{
	char	*str;
	int	i;

	i = 0;
	int fd = open("foo.txt", O_RDWR);
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%d : |%s|\n", i+1, str);
		printf("-----------------------------------------------------------\n");
		free (str);
		i++;
	}
		close(fd);
		str = get_next_line(fd);
		printf("%d : |%s|\n", i+1, str);
		printf("----------------------------------------------------------\n");
		free (str);
}*/
