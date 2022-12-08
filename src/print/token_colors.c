/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:51:51 by emakas            #+#    #+#             */
/*   Updated: 2022/12/08 18:31:31 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_colors.h"
#include "colors.h"

const char	*get_wordtokens(const t_token	*token, const t_cstate *state)
{
	if (state->in_quotes)
		return (GRN);
	else if (state->in_squotes)
		return (YEL);
	else if (state->is_first)
		return (BBLU);
	else if (state->is_redir)
		return (BCYN);
	else
		return (RST);
}
