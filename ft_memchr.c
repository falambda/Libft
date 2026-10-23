/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:22:04 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/18 21:19:27 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		c_aux;
	size_t				i;

	p = (const unsigned char *)s;
	c_aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == c_aux)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
