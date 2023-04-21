/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:15 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/21 12:20:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL || path[0] == '\0')
	{
		perror("getcwd");
		// g->exit_status = 1;
		return (-1);
	}
	ft_putendl_fd(path, 1);
	free(path);
	// g->exit_status = 0;
	return (0);
}
