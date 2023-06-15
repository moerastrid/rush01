/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 14:26:51 by ageels        #+#    #+#                 */
/*   Updated: 2023/06/15 16:16:22 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

enum	e_view {
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

int	validate_input(int argc, char **argv);
int	parse(int **view, int **map, char *input, int size);

#endif