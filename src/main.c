/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:37:47 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/15 13:34:17 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"
#define NBYTES 4096

void	ft_read_man_map(void)
{
	int		index;
	char	c;
	char	*mapa;

	index = 0;
	mapa = (char *)malloc(sizeof(char *));
	if (read(0, &c, 1) == 0)
		ft_putstr(2, "map error");
	while (read(0, &c, 1) > 0)
	{
		mapa[index] = (char)malloc(sizeof(char));
		mapa[index] = c;
		index++;
	}
	mapa[index] = '\0';
	if (index < 5)
	{
		ft_putstr(2, "map error");
		printf("I am 1");
		return ;
	}
	else
		ft_main_valid_map(mapa);
}
/* Reading manually introduced input map as an str of chars:
allocating memory for chars
read(if input 0, what you read, required nbytes for it)
index should min account for 1 int & 3 char + line break => 5 is min for ok map
if all ok => pass as valid map
https://www.geeksforgeeks.org/input-output-system-calls
-c-create-open-close-read-write/ */

void	ft_read_file_map(char *argv)
{
	int		index;
	int		fd;
	int		nb;
	char	buf[NBYTES + 1];
	char	*mapa;

	index = 1;
	fd = open(argv, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, buf, NBYTES) > 0)
			index++;
		mapa = (char *)malloc(sizeof(char) * (index * NBYTES) + 1);
		fd = open(argv, O_RDONLY);
		nb = read(fd, mapa, (index * NBYTES));
		mapa[nb] = '\0';
		ft_main_valid_map(mapa);
		close(fd);
	}
	else
	{
		ft_putstr(2, "map error");
		return ;
	}
}
/* fd :file descriptor; O_RDONLY only for reading,
  return fd = integer 0 on success -1 on error
If successful, read() returns the number of 
bytes actually read and placed in buf. 
This number is less than or equal to NBYTES.
https://linux.die.net/man/2/read 
https://www.cs.uky.edu/~raphael/programming.html*/

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc == 1)
		ft_read_man_map();
	else if (argc > 1)
	{
		while (argc > index)
		{
			ft_read_file_map(argv[index]);
			if (argc != index)
				ft_putstr(1, "\n");
			index++;
		}
	}
	return (0);
}
/* either we read manually introduced input map when argc=1, 
or multiple maps from files that are separated by line break */
