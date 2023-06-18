/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 15:53:40 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/18 17:18:08 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

static int	**set_view(char *input, int size)
{
	int		i;
	int		j;
	int		k;
	void	*temp;

	temp = malloc(sizeof(int *) * 5 + sizeof(int) * 4 * size);
	if (!temp)
		return (NULL);
	j = 0;
	k = 0;
	printf("test\n");
	while (j < 4)
	{
		((int **)temp)[j] = temp + 5 * sizeof(int *) + (j * size);
		i = 0;
		while (i < size)
		{
			((int **)temp)[j][i] = input[k];
			printf("%d ", ((int **)temp)[j][i]);
			i++;
			k += 2;
		}
		j++;
	}
	((int **)temp)[j] = NULL;

	printf("\n\n");
	printf("temp:\n");
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < size)
		{
			printf("%d ", ((int **)temp)[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}

	return ((int **)temp);
}

static char	**set_map(int size)
{
	int		i;
	int		j;
	void	*temp;

	temp = malloc((size + 1) * (sizeof(char *) + sizeof(char) * size));
	if (!temp)
		return (NULL);
	j = 0;
	while (j < size)
	{
		((char **)temp)[j] = temp + (size + 1) * sizeof(int *) + (j * size);
		i = 0;
		while (i <= size)
		{
			if (i != size)
				((char **)temp)[j][i] = '0';
			else
				((char **)temp)[j][i] = '\0';
			i++;
		}
		j++;
	}
	((int **)temp)[j] = NULL;
	return (temp);
}

int	parse(int ***view, char ***map, char *input, int size)
{
	*view = set_view(input, size);
	if (view == NULL)
		return (1);
	*map = set_map(size);
	if (map == NULL)
		return (1);
	return (0);
}
