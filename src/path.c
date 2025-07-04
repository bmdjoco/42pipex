/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:58:30 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/04 18:19:27 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prend en parametre une liste de variable de l'environnement
 * et renvoie la liste des paths dans un tableau de chaine de
 * charactere
 *
 * @param envp liste de variable de l'environnement
 */
char	**getpathlist(char **envp)
{
	int	i;
	char	*sub;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			sub = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			if(!sub)
				return (NULL);
			path = ft_split(sub, ':');
			if (!path)
				return (free(sub), NULL);
			return (free(sub), path);
		}
		i++;
	}
	return (NULL);
}

char	*access_path(char **envp, char *cmd)
{
	int	i;
	char	*tmp;
	char	*str;
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	if (!cmds)
		return (ft_putchar_fd("Error: cmd split failed\n", 2), NULL);
	if(access(cmds[0], X_OK))
		return (cmds[0]);
	i = 0;
	while (envp[i])
	{
		tmp = ft_strjoin(envp[i], "/");
		if (!tmp)
			return (free_split(cmds), ft_putchar_fd("Error: envp and / join failed\n", 2), NULL);
		str = ft_strjoin(tmp, cmds[0]);
		if(!str)
			return (free_split(cmds), free(tmp), ft_putchar_fd("Error: envp/ and cmd failed\n", 2), NULL);
		if(access(str, X_OK))
			return (free_split(cmds), free(tmp), str);
		free(tmp);
		free(str);
		i++;
	}
	return (free_split(cmds), ft_putchar_fd("Error: access path not found\n", 2), NULL);
}
