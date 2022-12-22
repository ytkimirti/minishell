/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:54:06 by emakas            #+#    #+#             */
/*   Updated: 2022/12/22 15:24:13 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_UTILS_H
# define WILDCARD_UTILS_H
# include "vector.h"

/*
 * Checks if source matches against pattern.
 * For example:
 * m*et -> mehmet, masdjkfet ...
 * *.* -> file.c, file.o.c ...
 * bwuh -> bwuh
 */
int		check_match(char *source, char *pattern);

int		check_start(char *str, char *pattern);
int		check_end(char *str, char *pattern);
void	vector_append_all(t_pvec *vector_dest, t_pvec *vector_src);

int		compare_char(char special, char str);
void	free_array(char **array);

#endif
