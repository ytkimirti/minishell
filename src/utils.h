/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:26:50 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/08 18:25:51 by ykimirti         ###   ########.tr       */
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

#endif
