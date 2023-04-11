/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:36:56 by nkietwee          #+#    #+#             */
/*   Updated: 2023/04/07 21:38:25 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			if (s[i] == '\0' || s[i] == c)
				count++;
		}
	}
	return (count);
}

static char	*ft_printword(char const *s, char c, size_t *start)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = 0;
	while (s[*start] == c)
	*start += 1;
	while (s[*start + len] != '\0' && s[*start + len] != c)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		res[i] = s[*start + i];
		i++;
	}
	*start += len;
	res[i] = '\0';
	return (res);
}

// char	**ft_split(char const *s, char c, size_t *count)
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	count;
	char	**ans;
	// *count = 0;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	// *count = ft_countword(s, c);
	count = ft_countword(s, c);
	// exit(0);
	// ans = (char **)malloc(sizeof(char *) * (*count + 1));
	ans = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ans)
		return (NULL);
	// while (i < *count)
	while (i < count)
	{
		ans[i] = ft_printword(s, c, &start);
		i++;
	}
	ans[i] = NULL;
	return (ans);
}

// int main(int ac, char **av)
// {
// 	size_t	*count=NULL;
// 	(void)ac;

// 	// *count = 0;
// 	// exit(0);
// 	char **str = ft_split(av[1], ' ' , count);
// 	exit(0);
// 	int i = 0;
// 	while(1)
// 	{
// 		printf("%s\n" ,str[i]);
// 		if (!str[i])
// 			break;
// 		i++;
// 	}
// 	return(0);
// }
