/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/18 14:04:15 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/19 15:17:14 by astrid        ########   odam.nl         */
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

static void	display_updown(int j, int **view, int size)
{
	int		i;
	char	c;

	i = 0;
	write(1, " ", 1);
	while (i < size)
	{
		c = view[j][i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	display_all(int **view, char **map, int size)
{
	int		i;
	char	c;
	char	d;

	display_updown(UP, view, size);
	i = 0;
	while (i < size)
	{
		c = view[LEFT][i];
		d = view[RIGHT][i];
		write(1, &c, 1);
		write(1, map[i], size);
		write(1, &d, 1);
		write(1, "\n", 1);
		i++;
	}
	display_updown(DOWN, view, size);
	write(1, "\n", 1);
}
