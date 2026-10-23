/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:14:16 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/09/30 18:22:48 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_aux;
	const unsigned char	*src_aux;

	dst_aux = dst;
	src_aux = src;
	while (n > 0)
	{
		*dst_aux++ = *src_aux++;
		n--;
	}
	return (dst);
}
