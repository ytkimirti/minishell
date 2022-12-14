/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:23:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/09 20:33:32 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

# include <stdbool.h>

typedef enum e_token_type
{
	EMPTY,
	WORD,
	WILDCARD_TOKEN,
	QUESTION_TOKEN,
	SPACE_TOKEN,
	VAR,
	PAREN_OPEN,
	PAREN_CLOSE,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
	AND_TOKEN,
	OR_TOKEN,
	PIPE_TOKEN,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	t_token_type;

typedef struct s_token
{
	int					len;
	enum e_token_type	type;
	const char			*str;
}	t_token;

bool	is_printable(enum e_token_type type);

#endif
