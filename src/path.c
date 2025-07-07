/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:58:30 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/07 20:55:41 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prend en parametre une liste de variable de l'environnement
 * et renvoie la liste des paths dans un tableau de chaine de
 * charactere
 *
 * @param envp liste de variables de l'environnement
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

/**
 * @brief Prend en parametre une liste de de path et
 * une commande pour renvoyer le path avec la commande
 * ou NULL en cas d'erreur
 *
 * @param path_lst liste des path possible
 * @param cmd commande rechercher
 */
char	*access_path(char **path_lst, const char *cmd)
{
	int	i;
	char	*tmp;
	char	*res;
	char	**cmds;

	if (!(cmds = ft_split(cmd, ' ')))
		return (ft_putstr_fd("Error: cmd split failed\n", 2), NULL);
	res = ft_strdup(cmds[0]);
	if(!access(res, X_OK))
		return (free_split(cmds), res);
	i = 0;
	free(res);
	while (path_lst[i])
	{
		tmp = ft_strjoin(path_lst[i], "/");
		if (!tmp)
			return (free_split(cmds), ft_putstr_fd("Error: envp and / join failed\n", 2), NULL);
		res = ft_strjoin(tmp, cmds[0]);
		free(tmp);
		if(!res)
			return (free_split(cmds), ft_putstr_fd("Error: envp/ and cmd join failed\n", 2), NULL);
		if(!access(res, X_OK))
			return (free_split(cmds), res);
		free(res);
		i++;
	}
	return (free_split(cmds), ft_putstr_fd("Error: access path not found\n", 2), NULL);
}


