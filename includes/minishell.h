/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:20 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 13:00:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "environment.h"
# include "signals.h"
# include "input.h"
# include "commands.h"
# include "builtins.h"
# include "redirect.h"
# include "error_messages.h"

# include <readline/readline.h>	//readline()
# include <readline/history.h>	//readline()
# include <errno.h>				//errno
# include <stdio.h>				//perror()
# include <fcntl.h>				//open()
# include <signal.h>			//struct sigaction

# define COLOR_GREEN	"\001\e[1;32m\002"
# define COLOR_RESET	"\001\e[0m\002"

typedef struct s_envp		t_envp;
typedef struct sigaction	t_sigaction;
typedef struct s_commands	t_cmd;
typedef struct s_redirect	t_redirect;

typedef struct s_quotes
{
	int				pos;
	char			*cont;
	int				envp;
	struct s_quotes	*next;
}	t_quotes;

typedef struct s_minishell
{
	int			exit_code;
	char		*input;
	char		*tml_host;
	char		*tml_line;
	char		**path;
	t_cmd		*cmd;
	t_envp		*envp;
	t_quotes	*quotes;
	t_redirect	*redir;
	t_sigaction	sa_signal;
	pid_t		pid;
}	t_minishell;

extern t_minishell			g_data;

// mini_hell/minishell_utils
void	terminate(char *s);
int		init_data(char **envp);
void	init_data_line(void);
void	free_path(void);
void	exit_terminal(void);
void	free_line(void);
void	exit_line(char *s, int n);
void	free_redir(void);

// mini_hell/terminal_line
char	*tml_get_pwd(void);
char	*tml_user_and_host(void);

// mini_hell/free_minishell
void	ft_free_array(char **arr);

// mini_hell/ft_mod_libft
char		*ft_strjoin_free(char *s1, char *s2);
int			ft_istrchr(const char *str, char c);
long int	ft_atoi_mod(char *nptr);
int			ft_isdigit_mod(char *string);

// quotes
void	compress_quotes(void);
void	decompress_quotes(char **cmd);
void	free_quotes(void);

// input/check_symbols.c
int	is_whitespace(char c);
int	is_redirect(char c);
int	is_invalid(char c);

#endif //MINISHELL_H