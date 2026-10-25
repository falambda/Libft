/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahab-d <fwahab-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:11:41 by fwahab-d          #+#    #+#             */
/*   Updated: 2026/10/25 13:15:59 by fwahab-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		write (fd, &str[length], 1);
		length++;
	}
}
