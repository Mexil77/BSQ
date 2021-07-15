/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:33:14 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 14:22:17 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		max_i;
	int		max_j;
	int		max_total_i;
	int		max_total_j;
	int		larg_i;
	int		larg_j;
	int		max_sqr;
	int		new_max_sqr;
	int		total_obst;
	char	**map;
	int		*obst;
	char	*str;
}						t_map;

/*here list all used functions*/
void	ft_read_man_map(void);
void	ft_read_file_map(char *argv);
void	ft_putstr(int inf, char *str);
int		ft_first_valid_map(char *mapa);
int		ft_ncol(int index, char *str);
int		ft_strlen(char *str);
int		ft_hard_atoi(char *str);
bool	ft_is_0(char str);
bool	ft_is_n(char str);
bool	ft_char_is_printable(char c);
char	**ft_cut_line(int index, int ncol, char *mapa, char **out);
int		ft_valid_out(int glo_nrow, char **out);
void	ft_main_valid_map(char *mapa);
int		solve(int c, int r, char **b, char *str);
void	ft_print_map(char **b, t_map map1);
void	ft_gen_final(t_map map1);
int		ft_find_sq(int i, int j, int index, t_map map1);
int		ft_next_obst(int i, int j, t_map map1);
void	ft_find_obst(t_map map1);
int		ft_count_obst(char **b, t_map map1);
char	*ft_first_line(int len_fl, char *mapa);
void	ft_find_cordenates(t_map map1);

#endif
