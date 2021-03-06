/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:28:55 by gpassos-          #+#    #+#             */
/*   Updated: 2021/04/25 12:18:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_zero_four(int vars[4])
{
	vars[0] = 0;
	vars[1] = 0;
	vars[2] = 0;
	vars[3] = 0;
}

static int	ft_split_wc(char const *s, char c)
{
	int	vars[4];

	ft_zero_four(vars);
	while (*(s + vars[0]) != '\0' || vars[3] == 0)
	{
		if (*(s + vars[0]) == '\0')
			vars[3] = 1;
		if (*(s + vars[0]) == c || vars[3] == 1)
		{
			if (vars[2] > 0)
				vars[1] += 1;
			vars[2] = 0;
		}
		else
			vars[2] += 1;
		vars[0] += 1;
		if (vars[3] == 1)
			break ;
	}
	return (vars[1]);
}

static int	ft_split_wa(char **saida, char const *s, char c)
{
	int	v[4];

	ft_zero_four(v);
	while (*(s + v[0]) != '\0' || v[3] == 0)
	{
		if (*(s + v[0]) == '\0')
			v[3] = 1;
		if (*(s + v[0]) == c || v[3] == 1)
		{
			if (v[2] > 0)
			{
				*(saida + v[1]) = (char *)malloc(sizeof(char)
						* ((unsigned long)v[2] + 1));
				if (*(saida + v[1]) == NULL)
					return (-1);
				v[1] += 1;
			}
			v[2] = 0;
		}
		else
			v[2] += 1;
		v[0] += 1;
		if (v[3] == 1)
			break ;
	}
	return (0);
}

static void	ft_split_set(char **saida, char const *s, char c)
{
	int	vars[4];

	ft_zero_four(vars);
	while ((*(s + vars[0]) != '\0') || vars[3] == 0)
	{
		if (*(s + vars[0]) == '\0')
			vars[3] = 1;
		if ((*(s + vars[0]) == c) || vars[3] == 1)
		{
			if (vars[2] > 0)
			{
				*(*(saida + vars[1]) + vars[2]) = ((char) '\0');
				vars[1] += 1;
			}
			vars[2] = 0;
		}
		else
		{
			*(*(saida + vars[1]) + vars[2]) = (char)*(s + vars[0]);
			vars[2] += 1;
		}
		vars[0] += 1;
		if (vars[3] == 1)
			break ;
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**saida;

	if (s == NULL)
		return (NULL);
	words = ft_split_wc(s, c);
	saida = (char **)malloc(sizeof(char *) * ((unsigned long)words + 1));
	if (saida == NULL)
		return (NULL);
	*(saida + words) = NULL;
	if (ft_split_wa(saida, s, c) == -1)
		return (NULL);
	ft_split_set(saida, s, c);
	return (saida);
}
