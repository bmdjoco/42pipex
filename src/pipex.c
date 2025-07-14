/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/15 00:28:50 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_here_doc(char *arg)
{
	return (ft_strncmp(arg, "here_doc", 9) == 0);
}

int main(int ac, char const **av, char **envp)
{
	int		here_doc;
	char	**path;

	if (ac < 5)
		return (ft_putstr_fd("Error: Pas suffisament d'argument\n", 2), 1);
	path = getpathlist(envp);
	if(!path)
		return (ft_putstr_fd("Error: Path error\n", 2), 1);
	here_doc = is_here_doc(av[1]);
	exec_all(av, envp, path, here_doc);
	free_split(path);
	return (0);
}
