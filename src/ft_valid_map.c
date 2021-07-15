/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:29:04 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 14:08:59 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq_header.h>

int	ft_first_valid_map(char *mapa)
{
	int		index;
	int		len_fl;

	index = 0;
	while (!(ft_is_n(mapa[index])))
	{
		if (!(ft_char_is_printable(mapa[index])))
			return (0);
		index++;
	}
	len_fl = index;
	if (ft_is_0(mapa[index + 1]))
		return (0);
	if (mapa[len_fl - 1] == mapa[len_fl - 2] \
			|| mapa[len_fl - 1] == mapa[len_fl - 3] \
			|| mapa[len_fl - 2] == mapa[len_fl - 3])
		return (0);
	while (!(ft_is_0(mapa[index])))
	{
		if (mapa[index] != mapa[len_fl - 2] && mapa[index] != mapa[len_fl - 3] \
				&& mapa[index] != '\n' && mapa[index] != '\0')
			return (0);
		index++;
	}
	return (len_fl);
}
/* read first line till line break, if next is 0 => error
extract the 3 chars: full, obstacle, empty; & integer as int by atoi(make hard)
if 3 chars are equal or  integer is <= 0 => error
continue to read the map till the end of file & check all symbols,
which could be empty or obstacle or line break
return the length of first line
!!!check that the map is only empty symbols or only obstacles!!!
*/

char	**ft_cut_line(int index, int ncol, char *mapa, char **out)
{
	int		j;
	int		k;
	int		flag;
	char	*hold;

	j = 0;
	while (!(ft_is_0(mapa[index])))
	{
		hold = (char *)malloc(sizeof(char) * ncol + 1);
		k = 0;
		flag = 0;
		while (!(ft_is_n(mapa[index])))
		{
			hold[k++] = mapa[index++];
			flag = 1;
		}
		if (flag == 1)
		{
			hold[k] = '\0';
			out[j++] = hold;
		}
		index++;
	}
	out[j] = 0;
	return (out);
}

int	ft_valid_out(int glo_nrow, char **out)
{
	int	index;
	int	nrow;
	int	len_col;

	index = 0;
	nrow = 0;
	len_col = ft_strlen(out[index]);
	while (out[index] != '\0')
	{
		if (len_col != ft_strlen(out[index]))
			return (0);
		index++;
		nrow++;
	}
	if (nrow != glo_nrow)
		return (0);
	else
		return (1);
}

void	ft_main_valid_map(char *mapa)
{
	int		ncol;
	int		glo_nrow;
	int		len_fl;
	char	**out;
	char	*str;

	len_fl = ft_first_valid_map(mapa);
	glo_nrow = ft_hard_atoi(mapa);
	if (len_fl == 0 || glo_nrow == 0)
	{
		ft_putstr(2, "map error");
		return ;
	}
	ncol = ft_ncol(len_fl, mapa);
	out = (char **)malloc(sizeof(char *) * glo_nrow + 1);
	if (out != NULL)
		out = ft_cut_line(len_fl, ncol, mapa, out);
	if (ft_valid_out(glo_nrow, out) == 0)
	{
		ft_putstr(2, "map error");
		return ;
	}
	str = ft_first_line(len_fl, mapa);
	solve(ncol, glo_nrow, out, str);
}
