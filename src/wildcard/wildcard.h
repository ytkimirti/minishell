/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:01:30 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/09 23:17:03 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H

# define WILDCARD_H
# include "token.h"
# include "vector.h"

# define ESC_WILDCARD_CHAR 7
# define ESC_QUESTION_CHAR 6

char	**expand_wildcard(char *);
t_pvec	*search_nodes(char *source, char **patterns);

#endif
