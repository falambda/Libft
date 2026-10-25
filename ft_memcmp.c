/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <fwahab-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:07:52 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/25 13:14:52 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_aux;
	const unsigned char	*s2_aux;

	s1_aux = (const unsigned char *)s1;
	s2_aux = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*s1_aux != *s2_aux)
			return (*s1_aux - *s2_aux);
		s1_aux++;
		s2_aux++;
		n--;
	}
	return (0);
}
