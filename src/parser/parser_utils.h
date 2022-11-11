/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:19:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/11 08:27:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H

# define PARSER_UTILS_H

# include "command.h"

// Calculates the char length the token will take
// when it's expanded
int		length_token(t_token *token);

int		length_tokens(t_token **tokens);

bool	is_command_token(t_token *token);

bool	is_redir_token(t_token *token);

int		strlencpy(char *dst, const char *src, int max_chars);

/*
 *	Continues to increment pointer while it 
 *	sees a space
 */
void	skip_spaces(t_token ***tokens);

/*
 * Expands and joins tokens until it sees a space or
 * a non command token. If no stringable
 */
char	*expand_tokens(t_token ***tokens);

#endif
