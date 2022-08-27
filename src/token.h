/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:23:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 16:42:23 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

enum e_token_type
{
	EMPTY,
	WORD,
	SPACE,
	PAREN_OPEN,
	PAREN_CLOSE,
	QUOTE_OPEN,
	QUOTE_CLOSE,
	SQUOTE_OPEN,
	SQUOTE_CLOSE,
};

typedef struct s_token
{
	int					len;
	enum e_token_type	type;
	char				*str;
}	t_token;

#endif
