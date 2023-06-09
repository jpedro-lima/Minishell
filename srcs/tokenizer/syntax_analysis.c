/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:17 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/24 12:21:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static int	put_error_message(char *str)
{
	g_data.exit_status = 2;
	ft_putstr_fd("minishell: syntax error near ", STDERR_FILENO);
	ft_putstr_fd("unexpected token `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	return (FALSE);
}

int	syntax_analysis(const t_token *tokens)
{
	int	is_pipe;

	is_pipe = tokens->token == PIPE;
	if (tokens->token == WORD)
		return (TRUE);
	if (tokens->token == INVALID)
		return (put_error_message(tokens->cont));
	if (tokens->next == NULL)
		return (put_error_message("newline"));
	if (tokens->next->token == PIPE)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == REDIRECT)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == APPEND)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == HEREDOC)
		return (put_error_message(tokens->next->cont));
	return (TRUE);
}
