/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:39:36 by emakas            #+#    #+#             */
/*   Updated: 2022/12/10 17:40:01 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcard.h"

int	compare_char(char special, char str)
{
	return (special != '?'
		&& ((str != special
				&& special != ESC_WILDCARD_CHAR && special != ESC_QUESTION_CHAR)
			|| (str != '*' && special == ESC_WILDCARD_CHAR)
			|| (str != '?' && special == ESC_QUESTION_CHAR)));
}
