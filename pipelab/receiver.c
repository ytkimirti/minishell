#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	buffer[1024];
	int	count;
	int	i;

	if (argc < 2)
		count = 0;
	else
		count = atoi(argv[1]);
	i = 0;
	while (i < count)
	{
		if (read(0, buffer, 1) == -1)
			perror("error!");
		dprintf(2, "receiver: Read '%c'\n", buffer[0]);
		i++;
	}
}
