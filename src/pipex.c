/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/05 14:57:31 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char const **av, char **envp)
{
	int		id_pipe[2];
	char	**path;
	char	*cmd;
	char	*test;

	(void)id_pipe;
	(void)ac;
	(void)av;
	/*if (ac < 5)
		perror("Pas suffisament d'argument");
	if (pipe(id_pipe) == -1)
		perror("Pipe error");*/
	path = getpathlist(envp);
	if(!path)
		return (1);
	test = ft_strdup("ls -a");
	if (!test)
		return (1);
	cmd = access_path(path, test);
	free(test);
	ft_printf("command : %s\n", cmd);
	free(cmd);
	free_split(path);
	return (0);
}
