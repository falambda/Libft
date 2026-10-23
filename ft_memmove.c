/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/01/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/10/18 21:31:44 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_aux;
	const unsigned char	*src_aux;

	dst_aux = (unsigned char *)dst;
	src_aux = (const unsigned char *)src;
	if (dst_aux > src_aux)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst_aux[i] = src_aux[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_aux[i] = src_aux[i];
			i++;
		}
	}
	return (dst);
}
