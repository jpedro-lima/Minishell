/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/17 15:19:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	recursive_redirections(void)
{
	t_redir	*aux;

	aux = g_data.redir->head_redir;
	while (aux)
	{
		redirect_function(aux->symbol, aux->key_word);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	free_redirects(&g_data.redir->head_redir);
}

void	start_redirection(t_redir **redirection)
{
	(*redirection) = malloc(sizeof(t_redir));
	(*redirection)->symbol = NULL;
	(*redirection)->key_word = NULL;
	(*redirection)->next = NULL;
}

void	keep_redir(char *symbol, char *key_word)
{
	t_redir	*aux;
	t_redir	*temp;

	aux = g_data.redir->head_redir;
	if (aux->symbol == NULL)
	{
		aux->symbol = ft_strdup(symbol);
		aux->key_word = ft_strdup(key_word);
		return ;
	}
	start_redirection(&temp);
	while (aux->next)
		aux = aux->next;
	temp->symbol = ft_strdup(symbol);
	temp->key_word = ft_strdup(key_word);
	aux->next = temp;
}

char	**redirections_handle_str(char **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = check_str(cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	start_redirection(&g_data.redir->head_redir);
	while (cmd && cmd[i])
	{
		if (cmd[i] && check_redirect(cmd[i]))
		{
			keep_redir(cmd[i], cmd[i + 1]);
			i++;
		}
		else
			aux[j++] =  ft_strdup(cmd[i]);
		if (cmd[i] == NULL)
			break ;
		i++;
	}
	aux[j] = NULL;
	recursive_redirections();
	return (aux);
}

void	redirections_handle(t_cmd **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = check_str((*cmd)->cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	start_redirection(&g_data.redir->head_redir);
	while ((*cmd)->cmd && (*cmd)->cmd[i])
	{
		if (check_redirect((*cmd)->cmd[i]))
		{
			keep_redir((*cmd)->cmd[i], (*cmd)->cmd[i + 1]);
			i++;
		}
		else
			aux[j++] =  ft_strdup((*cmd)->cmd[i]);
		if (!(*cmd)->cmd[i])
			break ;
		i++;
	}
	aux[j] = NULL;
	ft_free_array((*cmd)->cmd);
	free((*cmd)->path);
	(*cmd)->path = NULL;
	(*cmd)->path = cmd_path(aux[0]);
	(*cmd)->cmd = aux;
	recursive_redirections();
}
