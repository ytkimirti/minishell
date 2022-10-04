#include <stdio.h>


char *my_getenv(char *env)
{
	 getenv(env);
}

int main(int argc, char **argv, char *env[])
{
	for (int i = 0; i < argc; i++)
		printf(">%s<\n", argv[i]);

	char *my_env[] = {
		"A=23"
	};

	execv()
}
