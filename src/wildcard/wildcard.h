/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:01:30 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/09 20:30:06 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H

# define WILDCARD_H
# include "token.h"
# include "vector.h"

char	**expand_wildcard(char *expression);
t_pvec	*search_nodes(char *source, char **patterns);

#endif
