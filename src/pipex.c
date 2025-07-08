/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/08 13:48:14 by bdjoco           ###   ########.fr       */
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
