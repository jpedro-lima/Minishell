/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:36 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/20 21:27:00 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	new_node_envp(char *str)
{
	t_envp	*new;
	t_envp	*last;
	int		size_name;

	size_name = 0;
	new = (t_envp *)malloc(sizeof(t_envp));
	if (!new)
		terminate(ERR_ENVP_ALLOC);
	while (str[size_name] && str[size_name] != '=')
		size_name++;
	new->name = ft_substr(str, 0, size_name);
	new->cont = ft_substr(str, size_name + 1, ft_strlen(str) - size_name - 1);
	new->next = NULL;
	if (!new->name || !new->cont)
		terminate(ERR_ENVP_ALLOC);
	if (g_data.envp != NULL)
	{
		last = g_data.envp;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		g_data.envp = new;
	return (TRUE);
}

int	init_envp(char **envp)
{
	int		i;

	i = -1;
	g_data.envp = NULL;
	while (envp[++i] != NULL)
	{
		if (!new_node_envp(envp[i]))
		{
			free_envp();
			return (FALSE);
		}
	}
	return (TRUE);
}

char	*get_env(char *name)
{
	t_envp	*aux;

	aux = g_data.envp;
	while (aux != NULL)
	{
		if (!ft_strncmp(aux->name, name, ft_strlen(name)))
			return (aux->cont);
		aux = aux->next;
	}
	return (NULL);
}
