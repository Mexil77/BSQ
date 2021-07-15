/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:40:48 by emgarcia          #+#    #+#             */
/*   Updated: 2021/07/15 13:48:27 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq_header.h>

void	ft_find_obst(t_map map1)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	map1.obst = malloc((map1.max_i * map1.max_j) * sizeof(int));
	while (i < map1.max_i && map1.map[i][j] != '\0')
	{
		while (j < map1.max_j && map1.map[i][j] != '\0')
		{
			if (map1.map[i][j] == 'o')
			{
				map1.obst[k] = i;
				map1.obst[k + 1] = j;
				k += 2;
				map1.total_obst++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_next_obst(int i, int j, t_map map1)
{
	int	k;

	k = 0;
	while (k < 16)
	{
		if (k % 2 == 0)
			if (map1.obst[k] == i)
				if (j < map1.obst[k + 1])
					return (map1.obst[k + 1]);
		k++;
	}
	return (map1.max_j);
}

int	ft_find_sq(int i, int j, int index, t_map map1)
{
	int	k;
	int	l;

	k = i;
	l = j;
	while (k < index + 1 + (i - 1))
	{
		while (l < index + j)
		{
			if (k >= map1.max_total_i || l >= map1.max_total_j)
				return (index - 1);
			else if (map1.map[k][l] != '.')
				return (index - 1);
			l++;
		}
		l = j;
		k++;
	}
	return (ft_find_sq(i, j, index + 1, map1));
}

void	ft_print_map(char **b, t_map map1)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < map1.max_total_i)
	{
		while (j < map1.max_total_j)
		{
			write(1, &b[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int	solve(int c, int r, char **b)
{
	t_map	map1;

	map1.max_i = r;
	map1.max_j = c;
	map1.max_total_i = r;
	map1.max_total_j = c;
	map1.larg_i = r;
	map1.larg_j = c;
	map1.max_sqr = 0;
	map1.new_max_sqr = 0;
	map1.total_obst = 0;
	map1.map = b;
	map1.obst = 0;
	map1.obst = malloc(16 * sizeof(int));
	ft_find_obst(map1);
	ft_find_cordenates(map1);
	ft_gen_final(map1);
	ft_print_map(b, map1);
	return (0);
}
