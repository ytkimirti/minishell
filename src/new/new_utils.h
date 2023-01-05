/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:38:46 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/05 19:05:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_UTILS_H

# define NEW_UTILS_H

# include "token.h"
# include "tstdio.h"

bool	is_next_pipeline(t_token **tokens);

int		run_expr(t_token ***tokens, t_stdio std);

int		parse_and_run_command(t_token ***tokens, t_stdio std, bool is_sync);

/*
 * Jump to closing paren
 * |        |
 * ( () ()  )
 */
t_token	**jump_paren(t_token **tokens);

/*
 * Jump to a non space token after that command.
 * Supports parens too
 * |             |
 * ( COMMAND  )  && 
 *
 *    |             |
 *    ( COMMAND  )  && 
 */
t_token	**jump_primary(t_token **tokens);

t_token	**jump_pipeline(t_token **tokens);

t_token	**jump_to_end(t_token **tokens);

#endif
