/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 19:16:38 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# include <stdbool.h>
# include "token.h"

bool	*error_false(const char *msg);

void	*error_null(const char *msg);

void	error(const char *msg);

/*
 * Prints a unexpected token error with relevant info
 * about where the token is. If expected token is null
 * it only says "Unexpected token: <token_name>"
 */
void	error_unexpected(const t_token *token, t_token_type expected);

/*
 * Print's out perror and exits
 */
void	*malloc_error(void);

/*
 * Call this whenever your tokenization
 * finishes so in case there is an error
 * it can find which token it belongs to
 * and print relevant info.
 */
void	begin_trace(t_token **tokens, char *line);

/*
 * Invalidate the last trace data. Call this
 * before freeing the tokens.
 */
void	end_trace(void);

#endif
