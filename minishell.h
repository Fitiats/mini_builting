/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahanta <trahanta@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:14:21 by tmory             #+#    #+#             */
/*   Updated: 2025/01/08 00:53:26 by trahanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
#include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <unistd.h>
#include <fcntl.h>
# include <readline/readline.h> // for readline
# include <readline/history.h> // for readline ---> need flag -lreadline when compiling
#include <limits.h>
# define WORD 1
# define PIPE 2
# define OUTPUT 3
# define HEREDOC 4
# define OUT_HEREDOC 5
# define INPUT 6

//PARSING STRUCT
typedef struct s_redir
{
  char *file;
  int type;
  struct s_redir *next;
}	t_redir;

typedef struct  s_parsing
{
    char *cmd;
    char **arg;
    t_redir *redir;
	struct  s_parsing *next;
}	t_parsing;

typedef struct s_char_struct
{
	char *s;
	struct s_char_struct *next;
}	t_char_struct;

//-----------------

typedef struct 	s_sbw_variables
{
	const char	*s;
	int		*j;
}	t_sbw_variables;

//TOKEN STRUCT
typedef struct 	s_token
{
	char	*word;
	unsigned int rank;
	unsigned int	type;
	struct 	s_token	*next;
}	t_token;

//ENVIRONMENT COPY STRUCT
typedef struct 	s_env
{
	char	*var_name;
	char	*var_value;
	struct 	s_env *next;
}	t_env;

typedef struct s_list_swap
{
	char *current;
	char *next;
	char *temp_name;
	char *temp_value;
}t_swap;

//ms_check_token
int	ms_is_relationalop(char c); // search < or >
int ms_is_quotes(char c); // search "
int ms_is_singlequotes(char c); // search \'
int ms_is_allquotes(char c); // search both \' and "
int ms_is_pipe(char c);
int	ms_is_pipedouble(char *c);
int ms_check_error_nbpipe(const char *s);
int	ms_is_relopdouble(const char *c); // search << or >> (ms_is_supdouble || ms_is_infdouble)
int	ms_is_supdouble(const char *c); // search >> (take char &c and check the next address if have < or >)
int	ms_is_infdouble(const char *c); // search << (take char &c and check the next address if have < or >)
int	ms_isbackslash(const char c); // search "\"
int	ms_issemicolon(const char c); // search "\"

//utilities
void	ft_free_split(t_token *token);
void	ft_free_split_char(char	**tab_s);
void ms_free_env(t_env *env);
void	ms_lstadd_back(t_token **lst, t_token *new);
int	ft_strcmp(const char *s1, const char *s2);
void	ms_spltk_init_token(t_token *token, int i);
char	**ft_ms_split(char const *s, char c);

//utilities env
unsigned int ms_envcpy(t_env **env, char **src);

//split_token
t_token	*ms_split_token(char const *s, t_env *env, char c);
int	ms_test_quotes(const char *s);
int print_split(t_token *token);
int	ms_split_byword(int *k, t_token *token, const char *s);
int ms_sbw_dupmetachar(t_token *token, int *k, char *dup, int type);
int ms_sbw_dupmetachar2(t_token *token, int *k, char *dup, int type);
//split_byword_utils
void ms_sbw_count_len2(int *quote_indic, t_sbw_variables *var);
void ms_sbw_whileloop_2(int *quote_indic, t_sbw_variables *var, int *k, t_token *token);

//ms_expand
int ms_expand(t_token *tkn, t_env *env);

//test_split_quotes
void ms_recursive_quotes(const char *s, int *i);
int	**ft_free_malloc(char **p, int i);

// void	split_quote(t_token *token);
int	ms_clean_quotes(t_token *word);
		// int split_if_doublequotes(char *s);

//test_split_single_quotes
void	ms_recursive_singlequotes(const char *s, int *i);
// int ms_clean_quotes(char const *s, char c);
//"kj""jhg 'kh'"'jh'J|$RT$USER"kj""jhg 'kh'"'jh'J|"$HOME"'$GFGF"'>><<"$HOME"'$GFGF"'"k""j"'j'J$HOMO$HOME$HOME$HOME$HO"ME"
//test_trahanta --TEST FOR PRINTING
void print_pars(t_parsing *pars);
int print_split(t_token *token);
void print_charpp(char **tab);
void test_built(t_token *tkn, t_env *env);

//piping
int ms_count_pipe(t_token *token);
int	ms_env_to_char(t_env *env, char **list_env);

//ms_piping --parsing
int ms_parsing(t_token *tkn, t_parsing *pars);
void ms_free_pars(t_parsing *pars);
void ms_free_cmd(t_char_struct *lst);
void ms_free_arg( t_parsing *arg);
int ms_redir_error(t_token *tkn);

//ms_execution
int	ms_count_env(t_env *env);
int ms_execution(t_env *env_lst, t_parsing *pars);
int ms_exec_withredir(t_parsing *pars, char **path, char *path_string, char **envp);
int ms_exec_ifpipe(t_env *env_lst, t_token *tkn, t_parsing *pars);


//ms_builting

// int	ms_echo(t_token *tkn, t_env *env);
int	ms_echo(t_token *tkn);
t_token *ms_take_first_token(t_token *tkn, unsigned int rank);
int ms_export_var(t_token *tkn, t_env *env);
int	ms_unset(t_env **env, t_token *tkn);
void	ms_env(t_env *env);

//ms_builting utilities
char	*check_var_name(char *s);
void	print_env(t_env *env);
t_env	*find_var(t_env *env, char *var_name);
char	*ft_strndup(char *s, int n);


#endif
