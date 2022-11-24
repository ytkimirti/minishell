
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

int	open_output_file(const char *file, bool is_append)
{
	int	fd;
	int	append_mask;

	if (is_append)
		append_mask = O_APPEND;
	else
		append_mask = O_TRUNC;
	fd = open(file, O_CREAT | O_WRONLY | append_mask,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ((perror("open output file error"), -1));
	return (fd);
}

int	open_input_file(const char	*file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("open input file error"), -1);
	return (fd);
}
