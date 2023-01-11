/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:02:37 by ykimirti          #+#    #+#             */
/*   Updated: 2023/01/11 20:36:19 by ykimirti         ###   ########.tr       */
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
#include "env.h"
#include "prompt_utils.h"

char	*get_formatted_cwd(void)
{
	char			*cwd;
	char			*new;
	const char		*home;

	cwd = getcwd(NULL, 0);
	home = get_env("HOME", 4);
	if (home == NULL || home[0] == '\0')
		return (cwd);
	new = replace_prefix(cwd, home, "~");
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

char	*line_without_newline(void)
{
	char	*str;
	int		len;

	str = get_next_line(0);
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

char	*readline_with_prompt(void)
{
	char	*str;
	char	*res;

	if (!isatty(0))
		return (line_without_newline());
	str = create_prompt();
	res = readline(str);
	free(str);
	if (res != NULL && res[0] != '\0')
		add_history(res);
	return (res);
}
