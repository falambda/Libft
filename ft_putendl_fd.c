/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:13:52 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/18 21:07:29 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		write (fd, &str[length], 1);
		length++;
	}
	write (fd, "\n", 1);
}
