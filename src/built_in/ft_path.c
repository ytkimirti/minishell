/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:25:19 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/04 11:47:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include <stdlib.h>
#include "libft.h"
#include "colors.h"

int	ft_path(t_command *command, t_stdio std)
{
	const char	*str;
	int			i;
	bool		is_query;
	char		*bin;

	bin = "";
	if (command->argc == 3 && ft_strncmp(command->argv[1], "-q", 4) == 0)
	{
		bin = command->argv[2];
		is_query = true;
	}
	i = 0;
	while (true)
	{
		str = get_joined_path(bin, i);
		if (str == NULL)
			break ;
		if (is_query && access(str, X_OK) == 0)
			ft_putstr_fd(BGRN, std.out);
		ft_putstr_fd(str, std.out);
		ft_putstr_fd("\n" RST, std.out);
		i++;
	}
	return (0);
}
