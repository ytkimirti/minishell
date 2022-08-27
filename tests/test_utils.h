/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:56 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/27 16:19:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H

# define TEST_UTILS_H

# include "../src/tokenize_state.h"
# include "../src/token.h"
# include <string.h>

extern t_state	g_state;

t_token	*tokenize_word(char **str, t_state *state);
void	reset_state(void);
int		cr_user_t_token_eq(t_token *a, t_token *b);
char	*token_type_tostr(enum e_token_type type);
char	*cr_user_t_token_tostr(t_token *token);

#endif
