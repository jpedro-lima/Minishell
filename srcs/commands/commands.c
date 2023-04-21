/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/21 15:59:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	recursive_function(t_cmd *cmd, int redirect)
{
	int		fd[2];
	pid_t	pid;

	if (!cmd)
		return (FALSE);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		if (dup2(recursive_function(cmd->next, TRUE), fd[0]))
			dup2(fd[0], STDIN_FILENO);
		else
			close(fd[0]);
		if (redirect)
			dup2(fd[1], STDOUT_FILENO);
		else
			close(fd[1]);
		execve(cmd->path, cmd->cmd, g_data.envp_cmd);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	return (fd[0]);
}
	// if (check_builtin(*(cmd)->cmd))
	// 	return (execute_builtin(cmd));

int	run_command(void)
{
	int	fd;

	fd = recursive_function(g_data.cmd, FALSE);
	(void)fd;
	free_cmd();
	return (TRUE);
}

	// validate_command(); descomprimir os $(); -> vai ser feito antes
	// if (fd)
	// {
	// 	char *str;
	// 	while((str = get_next_line(fd)) != NULL)
	// 	{
	// 		printf("%s", str);
	// 		free(str);
	// 	}
	// }

