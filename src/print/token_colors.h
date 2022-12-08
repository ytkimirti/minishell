/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:51:56 by emakas            #+#    #+#             */
/*   Updated: 2022/12/08 17:53:56 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_COLORS_H
# define TOKEN_COLORS_H
# include "token.h"
# include "print.h"

const char	*get_wordtokens(const t_token	*token, const t_cstate *state);

#endif