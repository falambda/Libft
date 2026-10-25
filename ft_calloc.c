/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <fwahab-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:16:27 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/25 13:13:23 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*p_aux;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > (size_t)-1 / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	p_aux = p;
	while (i < count * size)
	{
		p_aux[i] = 0;
		i++;
	}
	return (p);
}
