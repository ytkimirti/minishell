/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:02:58 by ykimirti          #+#    #+#             */
/*   Updated: 2022/11/24 21:13:48 by emakas           ###   ########.fr       */
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
	signal(SIGPIPE, on_sigpipe);
	signal(SIGINT, on_sigpipe);
	while (argv[1][i] != '\0')
	{
		char c = argv[1][i];
		if (c == 'n')
			c = '\n';
		if (write(1, &c, 1) == -1)
		{
			perror("Write error!");
			break ;
		}
		dprintf(2, "Written: %c\n", argv[1][i]);
		i++;
	}
	dprintf(2, "Sender closed!\n");
}
