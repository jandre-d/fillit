/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 11:56:15 by jandre-d       #+#    #+#                */
/*   Updated: 2019/02/04 15:54:31 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "fillit.h"
# include "list.h"
# include <unistd.h>

t_tetrimino	*get_tetriminio_list(int fd);

#endif
