/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:18:25 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/18 21:58:03 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_count_symbols(long int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*ptr;
	size_t		len;
	size_t		start;

	nb = n;
	len = ft_count_symbols(nb);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	start = 0;
	if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
		start = 1;
	}
	while (len > start)
	{
		len--;
		ptr[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}
