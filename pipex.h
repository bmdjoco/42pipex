/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:42:54 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/15 00:40:58 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>

char		**getpathlist(char **envp);
char		*access_path(char **envp, const char *cmd);
void		child_process(char *cmd, char **envp, char **paths);
int			create_here_doc(char *limiter);

void		free_split(char **split);

#endif
