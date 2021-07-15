/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_library2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:46:40 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 14:08:07 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	ft_ncol(int index, char *str)
{
	int	ncol;

	ncol = 0;
	index = index + 1;
	while (!(ft_is_n(str[index])))
	{
		ncol++;
		index++;
	}
	return (ncol);
}
/* the index we pass corresponds to the line break
 * so we count from the next index what is the length till next line break */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (!(ft_is_0(str[index])))
		index++;
	return (index);
}

char	*ft_first_line(int len_fl, char *mapa)
{
	int		index;
	char	*str;

	str = (char *)malloc(sizeof(char) * len_fl + 1);
	index = 0;
	while (index <= len_fl)
	{
		str[index] = mapa[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
