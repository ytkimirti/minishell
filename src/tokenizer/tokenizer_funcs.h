/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:26:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 15:30:48 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_FUNCS_H

# define TOKENIZER_FUNCS_H

# include "tokenize_state.h"
# include "token.h"

/*
 * Tokenizes a word until it's not a name. Skips the
 * first '$' character. Pointer points after that.
 * */
t_token	*tokenize_var(const char **str, t_state *state);

/*
 * Tokenizes a word until;
 * 	if in a quote, until it sees $,
 * 	otherwise until it sees a metacharacter
 * */

/*
 * TODO: Make tokenizing a word a non freeable pointer thing.
 * Make it a pointer to the thing inside str.
 */
t_token	*tokenize_word(const char **str, t_state *state);

/*
 * Tokenizes a space just to seperate the tokens. For
 * example:
 * echo "Hello" "Boi"heh
 *
 * These will get tokenized like
 * Hello
 * Boi
 * heh
 *
 * But there is no way to know whether they are
 * seperated or joined.
 *
 * Note that the space must not be in a quote.
 * */
t_token	*tokenize_space(const char **str, t_state *state);

/*
 * Tokenizez both single and double quotes. It also modifies
 * the state variable.
 */
t_token	*tokenize_quote(char **str, t_state *state);

#endif
