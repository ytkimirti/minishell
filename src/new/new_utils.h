/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:38:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/04 18:55:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_UTILS_H

# define NEW_UTILS_H

# include "token.h"
# include "tstdio.h"

bool	is_next_pipeline(t_token **tokens);

int		run_expr(t_token ***tokens, t_stdio std);

int		parse_and_run_command(t_token ***tokens, t_stdio std, bool is_sync);

t_token	**jump_paren(t_token **tokens);

t_token	**jump_primary(t_token **tokens);

t_token	**jump_pipeline(t_token **tokens);

// Closes fd only if fd != exception
// Used like
// close_if_not_eq(std.in, 0)
// * close stdin if it's not 0 *
void	close_if_not_eq(int fd, int exception);

#endif
