/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/18 14:04:15 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/18 17:07:51 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void	display_map(char **map, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		write(1, map[j], size);
		write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	display_all(int **view, char **map, int size)
{
	int		i;
	int		j;
	int		k;
	char	c;
	char	d;

	(void)map;
	j = 0;
	k = 0;
	while (j < size)
	{
		i = 0;
		if (j == UP || j == DOWN)
		{
			write(1, " ", 1);
			while (i < size)
			{
				c = view[j][i];
				write(1, &c, 1);
				i++;
			}
		}
		else
		{
			while (k < size)
			{
				c = view[LEFT][k];
				d = view[RIGHT][k];
				write(1, &c, 1);
				write(1, map[k], size);
				write(1, &d, 1);
				write(1, "\n", 1);
				k++;
			}
		}
		write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
}
