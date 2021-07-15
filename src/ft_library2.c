/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_library2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agogolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:46:40 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 11:49:09 by agogolev         ###   ########.fr       */
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

/*int	ft_nrows(char *map)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (!(ft_is_0(map[index])))
	{
		if (ft_is_n(map[index]))
			count++;
		index++;
	}
	return (count);
}*/
/*count in map all line breaks in rows
 because last digit is \0 & first line compensate */
