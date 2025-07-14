/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:33:53 by bdjoco            #+#    #+#             */
/*   Updated: 2025/07/15 00:35:26 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_infile(char **av, int here_doc)
{
	int	fd;

	fd = -1;
	if (!here_doc)
		fd = open(av[1], O_RDONLY);
	else
		fd = create_here_doc(av[2]);
	if (fd < 0)
		perror("infile");
	return (fd);
}

int	open_outfile(char **av, int here_doc)
{
	int	fd;
	int	flags;
	int	mode;

	flags = O_CREAT | O_WRONLY;
	mode = 0644;
	if (here_doc)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(av[get_argc(av) - 1], flags, mode);
	if (fd < 0)
		perror("outfile");
	return (fd);
}

void	exec_all_bonus(char **av, char **envp, char **paths, int here_doc)
{
	int		infile;
	int		outfile;
	int		i;
	int		prev_fd;

	infile = open_infile(av, here_doc);
	outfile = open_outfile(av, here_doc);
	if (infile < 0 || outfile < 0)
		return ;
	i = 2 + here_doc;
	prev_fd = -1;
	while (av[i + 1])
	{
		process_command(av, envp, paths, i, &prev_fd, outfile);
		i++;
	}
	close(outfile);
	while (wait(NULL) > 0)
		;
}
