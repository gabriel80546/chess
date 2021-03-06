/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:58:28 by gpassos-          #+#    #+#             */
/*   Updated: 2021/04/25 12:15:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_p(char numeros[40], int fd)
{
	int	i;

	i = 0;
	while (i < 40)
	{
		if (numeros[i] != -1)
			ft_putchar_fd(numeros[i] + '0', fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	numeros[40];
	int		i;

	if (n == -2147483648LL)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	ft_memset(numeros, -1, 40);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = 39;
	while (n > 9)
	{
		numeros[i] = (n % 10);
		n = (n / 10);
		i--;
	}
	numeros[i] = (char)n;
	ft_putnbr_fd_p(numeros, fd);
}
