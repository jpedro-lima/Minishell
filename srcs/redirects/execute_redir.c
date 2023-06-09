/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:12:07 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 12:19:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_error(int fd, char *str)
{
	close(fd);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	return (FALSE);
}

int	redirect_function(t_redir *redir)
{
	int		i;
	int		fd;

	i = 0;
	if (redir->symbol[i] == '>')
	{
		if (redir->symbol[i + 1] && redir->symbol[++i] == '>')
			fd = open(redir->key_word, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(redir->key_word, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (redir->symbol[i] == '<')
	{
		if (redir->symbol[++i] == '<')
			fd = ft_here_doc(redir->key_word);
		else
			fd = open(redir->key_word, O_RDONLY);
		if (fd == -1)
			return (redir_error(fd, redir->key_word));
		dup2(fd, STDIN_FILENO);
	}
	close(fd);
	return (TRUE);
}
