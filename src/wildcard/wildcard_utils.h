/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:54:06 by emakas            #+#    #+#             */
/*   Updated: 2022/11/29 15:00:28 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_UTILS_H
# define WILDCARD_UTILS_H
# include "vector.h"

int		check_match(char *source, char *pattern);
int		check_start(char *str, char *pattern);
int		check_end(char *str, char *pattern);
void	vector_append_all(t_pvec *vector_dest, t_pvec *vector_src);

#endif