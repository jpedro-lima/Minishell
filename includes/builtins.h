/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:38 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/23 19:39:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef struct s_envp		t_envp;

//ft_cd.c
void	ft_cd(char **input);

//ft_echo.c
void	ft_echo(char **input);

//ft_env.c
void	ft_env(char **input);
void	ft_env_from_export(char **input);

//ft_exit.c
void	ft_exit(char **input);

//ft_export_check.c
char	**ft_var_export(char *cmd);
int		check_export_error(char *input);

//ft_export.c
void	ft_export(char **input);
int		is_varname(char c, int i);

//ft_pwd.c
void	ft_pwd(void);

//ft_unset.c
void	ft_unset(char **input);

//exit_minishell.c
void	exit_builtin(void);

#endif //BUILTINS_H