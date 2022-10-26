/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:50 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/16 14:04:17 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include "tokenizer.h"
# include "executer.h"

// Duplicate the str inside token
// and null terminate it
char	*dup_token_str(t_token *token);
void	print_cmd(t_cmd *cmd);
void	print_token(t_token *token);
void	print_tokens(t_token **tokens);

// Returns a non freeable string constant
char	*token_type_tostr(enum e_token_type type);

#endif
