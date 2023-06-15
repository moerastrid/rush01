/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:53:40 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/15 17:22:06 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	**set_view(char *input, int size)
{
	int		i;
	int		j;
	int		k;
	void	*temp;

	temp = malloc(sizeof(int *) * 5 + sizeof(int) * size);
	if (!temp)
		return (NULL);

	i = 0;
	j = 0;
	k = 0;
	while (j < 4)
	{
		((int **)temp)[j] = temp + 5 * sizeof(int *) + (j * size);
		i = 0;
		while (i < size)
		{
			((int **)temp)[j][i] = input[k];
			i++;
			k += 2;
		}
		j++;
	}
	((int **)temp)[j] = NULL;
	return ((int **)temp);
}

//static void	set_map(int **map, int size)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (j < size)
//	{
//		while (i < size)
//		{
//			map[i][j] = 0;
//			i++;
//		}
//		j++;
//	}
//}

int	parse(int **view, int **map, char *input, int size)
{
	view = set_view(input, size);
	//set_map(map, size);
	(void)map;
	return (0);
}
