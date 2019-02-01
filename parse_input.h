/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 13:27:32 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/01 15:51:33 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include "fillit.h"
# include <fcntl.h>
# include <stdlib.h>

int	parse_input(char *filename, t_state *state);

#endif
