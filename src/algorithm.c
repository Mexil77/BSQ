#include <bsq_header.h>

struct	s_map;

void	ft_gen_final(t_map map1)
{
	int	i;
	int	j;

	i = map1.larg_i;
	j = map1.larg_j;
	while (i < map1.max_sqr + map1.larg_i)
	{
		while (j < map1.max_sqr + map1.larg_j)
		{
			map1.map[i][j] = 'x';
			j++;
		}
		j = map1.larg_j;
		i++;
	}
}

void	ft_change_max_sq(int *i, int *j, t_map map1)
{
	map1.new_max_sqr = ft_find_sq(*i, *j, 0, map1);
	if (map1.new_max_sqr >= map1.max_sqr)
	{
		if (map1.new_max_sqr == map1.max_sqr)
		{
			if ((*i + *j) < (map1.larg_i + map1.larg_j))
			{
				map1.larg_i = *i;
				map1.larg_j = *j;
			}
		}
		else
		{
			map1.larg_i = *i;
			map1.larg_j = *j;
		}
		map1.max_sqr = map1.new_max_sqr;
		map1.max_i = map1.max_total_i - map1.max_sqr;
		map1.max_j = map1.max_total_j - map1.max_sqr;
		*j += 1;
	}
	else
		*j += 1;
}

void	ft_find_cordenates(t_map map1)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= map1.max_i)
	{
		while (j < map1.max_j)
		{
			if (map1.map[i][j] != 'o')
			{
				if (j < ft_next_obst(i, j, map1))
				{
					ft_change_max_sq(&i, &j, map1);
				}
				else
					j = ft_next_obst(i, j, map1) + 1;
			}
			else
				j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
