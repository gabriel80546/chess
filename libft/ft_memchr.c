/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:57:59 by gpassos-          #+#    #+#             */
/*   Updated: 2021/04/25 12:14:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		contador;
	size_t		i;
	const char	*saida;

	saida = s;
	contador = 0;
	i = 0;
	while (contador < n)
	{
		if (*(saida + i) == (char)c)
			return ((const void *)((const char *)saida + i));
		i++;
		contador++;
	}
	return (NULL);
}
