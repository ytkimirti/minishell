/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:44:07 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/04 18:44:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_utils.h"
#include "command.h"
#include "token.h"
#include "parser_utils.h"
#include <stdlib.h>
#include <assert.h>
#include "parser.h"
#include "ast.h"
#include "ast_utils.h"
#include "tstdio.h"
#include <stdio.h>
#include <unistd.h>
#include "error.h"
#include "libft.h"

int	parse_and_run_command(t_token ***tokens, t_stdio std, bool is_sync)
{
	t_command	*command;
	int			status;

	command = create_command(tokens);
	if (command == NULL)
		return (SHELL_ERROR);
	status = execute_command(command, std, is_sync);
	free(command);
	return (status);
}
