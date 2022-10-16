/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:21:55 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/16 14:27:13 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/colors.h"
#include "token.h"
#include "executer.h"
#include "utils.h"
#include <stdio.h>

// Returns a non freeable string constant
char	*token_type_tostr(enum e_token_type type)
{
	if (type == WORD)
		return "WORD";
	if (type == SPACE)
		return "SPACE";
	if (type == QUOTE_OPEN)
		return "QUOTE_OPEN";
	if (type == QUOTE_CLOSE)
		return "QUOTE_CLOSE";
	if (type == SQUOTE_OPEN)
		return "SQUOTE_OPEN";
	if (type == SQUOTE_CLOSE)
		return "SQUOTE_CLOSE";
	if (type == PAREN_OPEN)
		return "PAREN_OPEN";
	if (type == PAREN_CLOSE)
		return "PAREN_CLOSE";
	if (type == EMPTY)
		return "EMPTY";
	return "UNKNOWN";
}

void	print_cmd(t_cmd *cmd)
{
	char	*argv_str;
	char	*tmp;
	char	*new_arg;
	int		i;

	argv_str = ft_strdup("");
	i = 0;
	while (i < cmd->argc)
	{
		asprintf(&new_arg, "\t\t" YEL "\"%s\"" RST ",\n", cmd->argv[i]);
		tmp = argv_str;
		argv_str = ft_strjoin(argv_str, new_arg);
		free(tmp);
		free(new_arg);
		i++;
	}
	printf("(t_cmd) { "
			".path = " YEL "\"%s\"" RST ", "
			".argc = " MAG "%d" RST ", "
			".argv = {\n%s\t}\n}\n"
			,
			cmd->path, cmd->argc, argv_str);
	free(argv_str);
}

void	print_token(t_token *token)
{
	char	*token_str;

	if (token == NULL)
	{
		printf("NULL\n");
		return ;
	}
	token_str = NULL;
	if (token->str != NULL && token->type & PRINTABLE)
		token_str = dup_token_str(token);

	if (token_str != NULL)
	{
		printf("(t_token) {"
				".len = " MAG "%d" RST ", "
				".type = " MAG "%s" RST ", "
				".str = " YEL "\"%s\" " RST
				"}\n",
				token->len, token_type_tostr(token->type), token_str);
	}
	else
	{
		printf("(t_token) {"
				".type = " MAG "%s" RST " "
				"}\n",
				token_type_tostr(token->type));
	}

	free(token_str);
}


void	print_tokens(t_token **tokens)
{
	while (*tokens != NULL)
	{
		print_token(*tokens);
		tokens++;
	}
	print_token(*tokens);
}
