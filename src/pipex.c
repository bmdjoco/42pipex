/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/04 17:58:40 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char const **av, char **envp)
{
	int		id_pipe[2];
	char	**path;

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
	for (int i = 0; path[i] != NULL; i++) {
		printf("%s\n", path[i]);
	}
	free_split(path);
	return (0);
}
