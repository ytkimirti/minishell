/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:01:12 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/31 09:37:16 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "token.h"
# include "command.h"

/**
 * @brief Create a command object by parsing tokens until it
 * sees a control structure.
 * 
 * @param tokens 
 * @return t_command* 
 */
t_command	*create_command(t_token ***tokens);

#endif
