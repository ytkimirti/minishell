/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:02:37 by ykimirti          #+#    #+#             */
/*   Updated: 2022/12/29 14:57:14 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "rl_colors.h"
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
		prompt = ft_sprintf(RL_YEL "%s " RL_RST, cwd);
	else
		prompt = ft_sprintf(RL_YEL "%s " RL_RST "on " RL_MAG "%s " RL_RST,
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

	if (!isatty(0))
		return (get_next_line(0));
	str = create_prompt();
	res = readline(str);
	free(str);
	if (res != NULL && res[0] != '\0')
		add_history(res);
	return (res);
}
