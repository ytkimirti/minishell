/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:25 by emakas            #+#    #+#             */
/*   Updated: 2022/10/28 18:02:46 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HELPER_H

# define TOKEN_HELPER_H

# include "../tokenizer/token.h"

t_token		*get_first_word(t_token **tokens);

int			read_args(t_token **tokens, char ***argv);

#endif
