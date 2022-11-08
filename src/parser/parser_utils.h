/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:19:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 13:01:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H

# define PARSER_UTILS_H

# include "command.h"

// Calculates the char length the token will take
// when it's expanded
// TODO: This doesn't support variable stuff, it
// needs the environment stuff first for that
int		length_token(t_token *token);

int		length_tokens(t_token **tokens);

bool	is_command_token(t_token *token);

bool	is_redir_token(t_token *token);

int		strlencpy(char *dst, const char *src, int max_chars);

void	skip_spaces(t_token ***tokens);

#endif
