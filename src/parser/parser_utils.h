/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:19:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/29 14:46:51 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H

# define PARSER_UTILS_H

# include "command.h"

// Calculates the char length the token will take
// when it's expanded
int		length_token(t_token *token);

// Length until wildcard, space or redir token
int		length_tokens(t_token **tokens);

// Includes spaces and every token you can use between
// ( ) || && | tokens
bool	is_command_token(t_token *token);

// Checks for * and ?
bool	is_wildcard_token(const t_token *token);

// Checks for < > << and >>
bool	is_redir_token(t_token *token);

/*
 * Does this argument contain a wildcard?
 * Searches for a wildcard token until it sees a
 * space. If finds a wildcard token, returns true
 */
bool	is_wildcard_argument(t_token **token);

int		strlencpy(char *dst, const char *src, int max_chars);

/*
 *	Continues to increment pointer while it 
 *	sees a space
 */
void	skip_spaces(t_token ***tokens);

/*
 * Expands and joins tokens until it sees a space or
 * a non command token or a wildcard token.
 */
char	*expand_tokens(t_token ***tokens);

/*
 * Expands the wildcard token. It uses expand tokens in the
 * background since expand tokens stops when it sees a wildcard_token
 * or a non command token
 */
bool	expand_wildcard_argument(t_token ***tokens, t_pvec *args_vec);

void	append_to_pvec(char **arr, t_pvec *vec);

#endif
