/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:32:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/30 22:33:22 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

inline bool	is_printable(enum e_token_type type)
{
	return (type == WORD);
}
