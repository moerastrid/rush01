/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:26:37 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/19 15:01:01 by astrid        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	getsize(char **argv)
{
	int	i;
	int	totalsize;

	i = 0;
	totalsize = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '9' && i % 2 == 0)
			totalsize++;
		else if (argv[1][i] != ' ' || i % 2 != 1)
			return (-1);
		i++;
	}
	if (totalsize % 4 != 0)
		return (-1);
	return (totalsize / 4);
}

int	validate_input(int argc, char **argv)
{
	int	size;
	int	i;

	if (argc != 2)
		return (-1);
	size = getsize(argv);
	if (size == -1)
		return (size);
	i = 0;
	while (argv[1][i] != '\0' && argv[1][i + 1] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= ('0' + size))
			i += 2;
		else
			return (-1);
	}
	return (size);
}
