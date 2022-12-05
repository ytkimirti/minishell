/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:01:30 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/05 13:02:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H

# define WILDCARD_H
# include "token.h"
# include "vector.h"

char	**expand_wildcard(t_token *token);
t_pvec	*search_nodes(char *source, char **patterns);

#endif
