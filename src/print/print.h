/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:40:16 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/08 18:31:14 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H

# define PRINT_H

# include "token.h"

typedef struct s_cstate
{
	bool	in_squotes;
	bool	in_quotes;
	bool	is_first;
	bool	is_redir;
}	t_cstate;

/*
 * Prints the string str and color it using the tokens.
 */
void	print_colored_tokens(const char *str, t_token **tokens);

int		find_token_len(t_token *token);

#endif
