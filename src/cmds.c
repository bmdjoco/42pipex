/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 23:20:20 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/08 15:12:43 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_cmds(char **path, char *cmd, int *fdpipe)
{
	__pid_t	id;

	id = fork();
	if (id == -1)
		return (ft_putstr_fd("Error: fork\n", 2), 0);
	if (id == 0)
		parent(path, cmd, fdpipe);
	else if(id > 0)
		child(path, cmd, fdpipe);
}

void parent(parent)
