/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:01:52 by ykimirti          #+#    #+#             */
/*   Updated: 2022/10/04 15:44:25 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H

# define EXECUTER_H

typedef struct s_cmd
{
	char	*path;
	int		argc;
	char	**argv;
	int		stdin;
	int		stdout;
	int		stderr;
	int (*execute)(struct s_cmd *);
}	t_cmd;

void	execute_cmd(t_cmd *cmd);

#endif
