/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:02:58 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/12 16:11:48 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>

void	on_sigpipe(int sig)
{
	dprintf(2, "Got a sigpipe!\n");
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		exit(1);
	i = 0;
	// signal(SIGPIPE, on_sigpipe);
	while (argv[1][i] != '\0')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
}
