/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:44:37 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/27 13:55:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_H

# define NEW_H

# include "token.h"

/*
 * cat | cat | ls
 *   1   2  
 *
 * 1 - When you see a command, parse and execute it.
 * 2 - If you see an end or or, continue by using the exit status
 * of the last function. If you have to exit, use return (status);
 *
 * 3 - If you see a paren close, token error
 * 4 - If you see a paren open, fork it and and execute the parse 
 * paren function.
 */
int	execute_tokens(t_token **tokens);

#endif
