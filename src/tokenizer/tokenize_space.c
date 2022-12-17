/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/17 19:00:25 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize_state.h"
#include "token.h"
#include "libft.h"
#include "error.h"

t_token	*tokenize_space(char **str, t_state *state)
{
	t_token	*token;
	int		i;

	(void)state;
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_error();
	token->type = SPACE_TOKEN;
	i = 0;
	while ((*str)[i] != '\0' && ft_isspace((*str)[i]))
		i++;
	(*str) += i;
	token->len = i;
	return (token);
}
