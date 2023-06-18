/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:13:34 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/18 14:57:07 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	error_return(int a)
{
	write(2, "Error\n", 6);
	return (a);
}

int	main(int argc, char **argv)
{
	int		size;
	int		**view;
	char	**map;

	view = NULL;
	map = NULL;
	size = validate_input(argc, argv);
	if (size <= 0)
		return (error_return(1));
	if (parse(&view, &map, argv[1], size))
		error_return(1);
	display_all(view, map, size);
	display_map(map, size);
	free(view);
	free(map);
	return (0);
}
