/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:40:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 18:01:46 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H

# define PRINT_H

# include "token.h"

/*
 * Prints the string str and color it using the tokens.
 */
void	print_colored_tokens(const char *str, t_token **tokens);

int		find_token_len(t_token *token);

#endif
