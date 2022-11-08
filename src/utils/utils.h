/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:50 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/08 18:20:44 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include "command.h"
# include "tokenizer.h"
# include "ast.h"

// Duplicate the str inside token
// and null terminate it
char	*dup_token_str(t_token *token);
// void	print_cmd(t_cmd *cmd);
void	print_token(t_token *token);
void	print_tokens(t_token **tokens);

// Returns a non freeable string constant
char	*token_type_tostr(enum e_token_type type);
char	*node_type_tostr(t_node_type type);

char	*token_tostr(t_token *token);

#endif
