/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <fwahab-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:17:21 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/24 14:43:52 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char	number;
	long	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd (n / 10, fd);
	number = '0' + n % 10;
	write (fd, &number, 1);
}
