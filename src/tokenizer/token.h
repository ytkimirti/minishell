/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:23:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 14:12:23 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

enum e_token_type
{
	EMPTY,
	WORD,
	SPACE,
	VAR,
	PAREN_OPEN,
	PAREN_CLOSE,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
};

# define PRINTABLE (WORD)

typedef struct s_token
{
	int					len;
	enum e_token_type	type;
	const char			*str;
}	t_token;

#endif
