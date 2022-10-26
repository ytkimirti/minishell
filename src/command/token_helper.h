/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:14:25 by emakas            #+#    #+#             */
/*   Updated: 2022/10/26 16:58:15 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_ADAPTER

# define TOKEN_ADAPTER

# include "../tokenizer/token.h"

t_token 	*get_first_word(t_token **tokens);

id_t		read_args(t_token **, char ***argv);

#endif
