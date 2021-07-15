/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_library1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:28:42 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 13:33:22 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	ft_putstr(int inf, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (inf, &str[i], 1);
		i++;
	}
}

int	ft_hard_atoi(char *mapa)
{
	int	index;
	int	i;
	int	count;
	int	len;

	index = 0;
	while (!(ft_is_n(mapa[index])))
		index++;
	len = index;
	i = 0;
	count = 0;
	while (i < (len - 3))
	{
		while (mapa[i] >= 48 && mapa[i] <= 57)
		{
			count = (count * 10) + (mapa[i] - 48);
			i++;
		}
	}
	return (count);
}

bool	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

bool	ft_is_0(char str)
{
	return (str == '\0');
}

bool	ft_is_n(char str)
{
	return (str == '\n');
}
