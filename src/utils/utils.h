/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:50 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/04 18:59:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include "command.h"
# include "tokenizer.h"
# include "ast.h"

// Duplicate the str inside token
// and null terminate it
// TODO: Remove this
char	*dup_token_str(t_token *token);
// void	print_cmd(t_cmd *cmd);
void	print_token(t_token *token);
void	print_tokens(t_token **tokens);

// Returns a non freeable string constant
char	*token_type_tostr(enum e_token_type type);
char	*node_type_tostr(t_node_type type);

/*
 * Returns the non debug string version of token type
 * like PAREN_OPEN to "("
 *
 * Lack of a better name :(
 * Should rename the top functions as token_type_debug
 * in the future
 */
char	*token_type_repr(t_token_type type);

/*
* Closes fd only if fd != exception
* Used like
* close_if_not_eq(std.in, 0)
* // close stdin if it's not 0
*/
void	close_if_not_eq(int fd, int exception);

#endif
