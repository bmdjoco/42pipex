/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 23:20:20 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/15 00:42:29 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	create_here_doc(char *limiter)
{
	int		fd[2];
	char	*line = NULL;

	if (pipe(fd) == -1)
		return (perror("pipe"), -1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break;
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)) &&
			line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}

void	child_process(char *cmd, char **envp, char **paths)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		exit(ft_putstr_fd("cmd error\n", 2), 1);
	if (access(args[0], X_OK) == 0)
		execve(args[0], args, envp);
	path = access_path(paths, cmd);
	if (!path)
	{
		free_split(args);
		exit(ft_putstr_fd("Command not found\n", 2), 127);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	free_split(args);
	exit(1);
}

void	run_child(char **av, char **envp, char **paths, int i,
					int prev_fd, int *fd, int outfile)
{
	int	last;

	last = (av[i + 1] == NULL);
	if (i == 2 || (i == 3 && is_here_doc(av[1])))
		dup2(prev_fd == -1 ? open_infile(av, is_here_doc(av[1])) : prev_fd, 0);
	else
		dup2(prev_fd, 0);
	if (!last)
		dup2(fd[1], 1);
	else
		dup2(outfile, 1);
	if (prev_fd != -1)
		close(prev_fd);
	if (!last)
		close(fd[0]);
	child_process(av[i], envp, paths);
}

void	process_command(char **av, char **envp, char **paths,
						int i, int *prev_fd, int outfile)
{
	int		fd[2];
	pid_t	pid;
	int		last;

	last = (av[i + 1] == NULL);
	if (!last && pipe(fd) == -1)
		return (perror("pipe"));
	pid = fork();
	if (pid == -1)
		return (perror("fork"));
	if (pid == 0)
		run_child(av, envp, paths, i, *prev_fd, fd, outfile);
	if (*prev_fd != -1)
		close(*prev_fd);
	if (!last)
	{
		close(fd[1]);
		*prev_fd = fd[0];
	}
}
