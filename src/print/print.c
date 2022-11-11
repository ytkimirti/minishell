/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:42:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/10 17:08:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "colors.h"
#include "libft.h"
#include "error.h"
#include "utils.h"
#include "parser_utils.h"

typedef struct s_cstate
{
	bool	in_squotes;
	bool	in_quotes;
	bool	is_first;
	bool	is_redir;
}	t_cstate;

int	find_token_len(t_token *token)
{
	if (token->type == WORD
		|| token->type == SPACE)
		return (token->len);
	else if (token->type == VAR)
		return (token->len + 1);
	else if (token->type == REDIR_APPEND
		|| token->type == OR_TOKEN
		|| token->type == AND_TOKEN)
		return (2);
	else
		return (1);
}

const char	*find_token_color(const t_token	*token, const t_cstate *state)
{
	if (token->type == SPACE)
		return (RST);
	else if (token->type == WORD)
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
	else if (token->type == PIPE_TOKEN)
		return (CYN);
	else if (token->type == AND_TOKEN || token->type == OR_TOKEN)
		return (BLU);
	else if (token->type == SINGLE_QUOTE)
		return (YEL);
	else if (token->type == DOUBLE_QUOTE)
		return (GRN);
	return (BCYN);
}

// TODO: Make these const
static void	update_state(t_cstate *state, t_token *prev,
		t_token *curr)
{
	if (prev == NULL || !is_command_token(curr))
		state->is_first = true;
	else if (curr->type == SPACE && is_command_token(prev))
		state->is_first = false;
	if (curr->type == DOUBLE_QUOTE)
		state->in_quotes = !state->in_quotes;
	else if (curr->type == SINGLE_QUOTE)
		state->in_squotes = !state->in_squotes;
	if (is_redir_token(curr))
		state->is_redir = true;
	else if (curr->type == SPACE)
		state->is_redir = false;
}

/*
 * Check if sum of token lengths is bigger than the
 * actual string length. Returns true in overflow
 */
bool	check_overflow(const char *str, t_token **tokens)
{
	int	strlen;
	int	len;
	int	i;

	i = 0;
	len = 0;
	strlen = ft_strlen(str);
	while (tokens[i] != NULL)
		len += find_token_len(tokens[i++]);
	if (len > strlen)
		ft_printf(BRED "%s" RST "\n", str);
	return (len > strlen);
}

void	print_colored_tokens(const char *str, t_token **tokens)
{
	int			i;
	int			pos;
	int			len;
	t_cstate	state;

	state = (t_cstate){false, false, false, false};
	i = 0;
	pos = 0;
	len = 0;
	if (check_overflow(str, tokens))
		return ;
	while (tokens[i] != NULL)
	{
		if (i == 0)
			update_state(&state, NULL, tokens[i]);
		else
			update_state(&state, tokens[i - 1], tokens[i]);
		len = find_token_len(tokens[i]);
		ft_putstr_fd(find_token_color(tokens[i], &state), 1);
		write(1, str + pos, len);
		pos += len;
		i++;
	}
	write(1, "\n", 1);
}