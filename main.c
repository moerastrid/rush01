/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:13:34 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/15 17:22:35 by ageels        ########   odam.nl         */
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
	int	size;
	int	**view = NULL;
	int	**map = NULL;

	size = validate_input(argc, argv);
	if (size <= 0)
		return (error_return(1));
	if (parse(view, map, argv[1], size))
		error_return(1);
	//print_all();
	//print_map();
	return (0);
}
