/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/18 01:00:41 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp, char **path)
{
	char	*full_path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		return (free_split(path),
			ft_putstr_fd("Error: split\n", 2));
	full_path = access_path(path, cmd);
	if (!full_path)
		return (free_split(args), free_split(path),
			ft_putstr_fd("Error: access error\n", 2));
	execve(full_path, args, envp);
	free_split(path);
	free_split(args);
	free(full_path);
	exit(2);
}

static void	exec_end(int pipefd[2], pid_t pid1, pid_t pid2, char **path)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_split(path);
}

void	exec_pipex(char const **av, char **path,
					int infile, int outfile)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (close(infile), close(outfile), free_split(path));
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_cmd((char *)av[2], path, path);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		exec_cmd((char *)av[3], path, path);
	}
	exec_end(pipefd, pid1, pid2, path);
}

int main(int ac, char const **av, char **envp)
{
	char	**path;
	int		infile;
	int		outfile;

	if (ac != 5)
		return (ft_putstr_fd("Error: Pas suffisament d'argument\n", 2), 1);
	path = getpathlist(envp);
	if(!path)
		return (ft_putstr_fd("Error: Path error\n", 2), 1);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		return (ft_putstr_fd("Error: Open Infile error\n", 2), 1);
	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		return (close(infile), ft_putstr_fd("Error: Open Outfile error\n", 2), 1);
	exec_pipex(av, path, infile, outfile);
	return (0);
}
