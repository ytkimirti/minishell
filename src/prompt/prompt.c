/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:02:37 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/12 09:56:24 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "colors.h"
#include "prompt_utils.h"

char	*get_formatted_cwd(void)
{
	char		*cwd;
	char		*new;

	cwd = getcwd(NULL, 0);
	new = replace_prefix(cwd, "/Users/kimirti", "~");
	if (new == NULL)
		return (cwd);
	free(cwd);
	return (new);
}

char	*create_prompt(void)
{
	char	*prompt;
	char	*cwd;
	char	*git;

	cwd = get_formatted_cwd();
	git = get_git_branch();
	if (git == NULL)
		prompt = ft_sprintf(YEL "%s " RST, cwd);
	else
		prompt = ft_sprintf(YEL "%s " RST "on " MAG "%s " RST,
				cwd, git);
	if (git != NULL)
		free(git);
	free(cwd);
	return (prompt);
}

char	*readline_with_prompt(void)
{
	char	*str;
	char	*res;

	str = create_prompt();
	res = readline(str);
	free(str);
	if (res != NULL && res[0] != '\0')
		add_history(res);
	return (res);
}
