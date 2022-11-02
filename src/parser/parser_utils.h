/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:19:17 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/02 16:07:24 by ykimirti         ###   ########.tr       */
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

#endif
