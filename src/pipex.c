/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/07 23:25:35 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char const **av, char **envp)
{
	int		fdpipe[2];
	char	**path;

	fdpipe;
	if (ac < 2 )
		return (ft_putstr_fd("Error: Pas suffisament d'argument\n", 2), 1);
	if (pipe(fdpipe) == -1)
		return (ft_putstr_fd("Error: Pipe error\n", 2), 1);
	path = getpathlist(envp);
	if(!path)
		return (ft_putstr_fd("Error: Path error\n", 2), 1);
		
	return (0);
}

/* Save
	int		id_pipe[2];
	char	**path;
	char	*cmd;

	(void) id_pipe;
	(void) ac;
	(void) av;
	if (ac < 2 )
		perror("Pas suffisament d'argument");
	if (pipe(id_pipe) == -1)
		perror("Pipe error");
	path = getpathlist(envp);
	if(!path)
		return (1);
	cmd = access_path(path, av[1]);
	if (cmd)
	{
		ft_printf("command : %s\n", cmd);
		free(cmd);
	}
	free_split(path);
*/
