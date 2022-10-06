/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:01:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/06 11:10:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "executer.h"
# include "tokenizer.h"

// Creates a cmd from the given tokens list.
// On error, it returns a cmd object with
// path set to NULL.
t_cmd	create_cmd(t_token **tokens);

// Frees the contents of the given cmd.
// So it frees the argv list.
void	free_cmd(t_cmd *cmd);

#endif
