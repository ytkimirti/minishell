/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:26:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 17:27:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_FUNCS_H

# define TOKENIZER_FUNCS_H

# include "tokenize_state.h"
# include "token.h"

t_token	*tokenize_var(char **str, t_state *state);
t_token	*tokenize_word(char **str, t_state *state);
t_token	*tokenize_space(char **str, t_state *state);

#endif
