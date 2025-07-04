/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:44 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/04 13:12:01 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Prend en parametre une liste de variable de l'environnement
 *
 * @param
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
