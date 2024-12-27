//TEST_TOKEN
//int	main(int ac, char **av, char **envp)
// {
// 	char *cmd;
// 	int i; //test

// 	(void)av;
// 	(void)envp;
// 	if (ac != 1)
// 		return (printf("error\n"), 1);
// 	while (1)
// 	{
// 		i = 0; //test
// 		cmd = readline("$>");
// 		//TEST_TOKEN
// 		if (ms_check_error_nbpipe(cmd) == 1)
// 			return ( printf("have a ||\n"), 0);
// 		while (cmd[i])
// 		{
// 			if (ms_is_relopdouble(&cmd[i]) == 1)
// 				return ( printf("have a double <<\n"), 0);
// 			if (ms_is_relationalop(cmd[i]) == 1)
// 				return ( printf("have a < or > operator\n"), 0);
// 			if (ms_is_pipe(cmd[i]) == 1)
// 				return ( printf("have a | \n"), 0);
// 			if (ms_is_quotes(cmd[i]) == 1)
// 				return ( printf("have a \" \n"), 0);
// 			if (ms_isbackslash(cmd[i]) == 1)
// 				return ( printf("have a \\ \n"), 0);
// 			i++;
// 		}
// 		printf(" %s\n", cmd);
// 		//ENDTEST_TOKEN
		
// 		add_history(cmd);
// 		free(cmd);
// 	}
// 	return (0);
// }
//ENDTEST_TOKEN

//VALGRIND_NO_READLINE_LEAKS
//valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./minishell
//-------++++++END VALGRIND_NO_READLINE_LEAKS

//MAIN TEST
#include "../minishell.h"
#include <readline/tilde.h>
#include <stdio.h>

//PRINT_SPLIT
volatile sig_atomic_t stop_requested = 0;
void handle_signal(int sig)
{
    if (sig == SIGINT)
	{
        // Set a flag to handle later
        stop_requested = 1;
		printf("\n");
        // Re-display the prompt properly
        rl_replace_line("", 0);      // Clear the current input line
		rl_on_new_line();        // Refresh the display with a new line
		rl_redisplay();  
    }
}

//---------+++++++END PRINT_SPLIT

//MAIN_SPLIT SIMPLE
int	main(int ac, char **av, char **envp)
{
	char *cmd;
	t_env *env;
	t_parsing pars;
	// t_token *fisrt_token;
	// int i; //test
	t_token *tokens;
	// char **g=(char *[]) {"kjh", "", ";k", NULL};

	(void)av;
    signal(SIGINT, handle_signal);
	if (ac != 1)
		return (printf("error\n"), 1);
	//---------COPY ENV
	env = NULL;
	if (ms_envcpy(&env, envp))
		return (1);
	//---------COPY ENV END
	
	while (1)
	{
		//SIGNAL --NEED to handle the global variable--is it usefull??
		if (stop_requested) {
        	stop_requested = 0;
			ms_free_env(env);
            break;
        }

		cmd = readline("$>");
		if (cmd[0] == '\0')
		{
        	rl_on_new_line();
			continue;
		}
		add_history(cmd);
		if (ms_test_quotes(cmd) == 1)
		{
			ft_putendl_fd(" error in quotes", STDERR_FILENO);
			free(cmd);
			continue;
		}
		printf("cmd = %s\n", cmd);

		//LEXING BEGIN
		tokens = ms_split_token(cmd, env, ' ');
		if ( tokens == NULL)
			return (ms_free_env(env), 1);
		// if (ms_ispipe)
		// 	ms_piping();
		// else
			// ms_execution();
		// print_split(tokens); //PRINT RESULT
		//test_builtings
		//test_built(tokens, env);
		//fisrt_token = NULL;
		// fisrt_token = ms_take_first_token(tokens, 2);
		//printf("%s\n", fisrt_token->word);
		
		if(ms_redir_error(tokens))
		{
			ft_free_split(tokens);
			free(cmd);
			ms_free_env(env);
			return (2);
		}
		//LEXING END
		if (ms_count_pipe(tokens))
		{
			printf("\033[32m A GERER si pipe \033[0m\n");
		// 	if (ms_exec_ifpipe(env, tokens, &pars))
		// 		return (1111);
		}
		else
		{
			if (ms_parsing(tokens, &pars))
				return (ms_free_pars(&pars), 1);
			if(ft_strcmp(pars.cmd, "/echo") == 0)
				ms_echo(tokens);
			else if(ft_strcmp(pars.cmd, "/export") == 0)
				ms_export_var(tokens, env);
			// else if(ft_strcmp(pars.cmd, "/pwd") == 0)
			// 	ms_pwd();
			// else if(ft_strcmp(pars.cmd, "/exit") == 0)
			// 	ms_exit();
			// else if(ft_strcmp(pars.cmd, "/export") == 0)
			// 	ms_export_var(tokens, env);
			else
				ms_execution(env, &pars);

		}
		//PARSING BEGIN
		
		// PARSING END
		// if (ms_parsing(tokens, &pars))
		// {
		// 	ms_free_pars(&pars);
		// 	ft_free_split(tokens);
		// 	free(cmd);
		// 	printf("\033[9m ERROR in aloccation of parsing \033[0m\n");
		// 	// ms_free_env(env);
		// 	continue;

		// }
		//print_pars(&pars);//PRINT RESULT
		ms_free_pars(&pars);
		ft_free_split(tokens);
		free(cmd);
        // rl_on_new_line();

	}
	return (0);
}
//---------+++++++END_MAIN_SPLIT SIMPLE
//"ad""k l" ljsh"kl c""kjs" | jsk "-ls"

// 





