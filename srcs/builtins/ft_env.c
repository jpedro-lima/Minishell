/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:50 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 12:11:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env_error(char *nextinline)
{
	g_data.exit_status = 127;
	ft_putstr_fd("minishell: env: ‘", STDERR_FILENO);
	ft_putstr_fd(nextinline, STDERR_FILENO);
	ft_putstr_fd("’: invalid parameter\n", STDERR_FILENO);
}

void	ft_env_from_export(char **input)
{
	t_envp	*aux;

	aux = g_data.envp;
	if (input[1])
		return (ft_env_error(input[1]));
	else
	{
		while (aux->next)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(aux->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(aux->cont, 1);
			ft_putstr_fd("\n", 1);
			aux = aux->next;
		}
	}
}

void	ft_env(char **input)
{
	t_envp	*aux;

	aux = g_data.envp;
	if (input[1])
		return (ft_env_error(input[1]));
	else
	{
		while (aux->next)
		{
			ft_putstr_fd(aux->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(aux->cont, 1);
			ft_putstr_fd("\n", 1);
			aux = aux->next;
		}
		ft_putstr_fd(aux->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(aux->cont, 1);
		ft_putstr_fd("\n", 1);
	}
}
