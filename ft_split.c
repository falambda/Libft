/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 12:05:16 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/18 22:14:14 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
	return (NULL);
}

static char	**fill(char **res, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			res[i] = ft_substr(s, 0, len);
			if (!res[i])
				return (free_all(res, i));
			i++;
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill(res, s, c));
}
