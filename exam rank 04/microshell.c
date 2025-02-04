#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return 1;
}

int cd(int argc, char **argv)
{
	if (argc != 2)
		return err("error: cd: bad arguments\n");
	else if (chdir(argv[1]) == -1)
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
	return 0;
}

int exec(int i, char **argv, char **env)
{
	int fd[2];
	int status = 0;
	int is_pipe;

	is_pipe = argv[i] && !strcmp(argv[i], "|");
	if (is_pipe && pipe(fd) == -1)
		return err("error: fatal\n");
	
	int pid = fork();
	if (pid == 0)
	{
		argv[i] = 0;
		if (is_pipe && (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return err("error: fatal\n");
		execve(*argv, argv, env);
		return err("error: cannot execute "), err(argv[0]), err("\n");
	}
	waitpid(pid, &status, 0);
	if (is_pipe && (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return err("error: fatal\n");
	return status;
}

int main(int argc, char **argv, char **env)
{
	int i = 0, result = 0;
	if (argc == 1) return 0;
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";")) i++;
		if (strcmp(argv[0], "cd") == 0) result = cd(i, argv);
		else if (i) result = exec(i, argv, env);
	}
	return result;
}
