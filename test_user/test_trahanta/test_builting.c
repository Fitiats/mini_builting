
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>



int	main(void)
{
	char *prompt;

	while ((prompt = readline("$>")) != NULL)
	{
		if (*prompt)
		{
			add_history(prompt);
			printf("Valeur d entrer : %s\n", prompt);
		}
		free(prompt);
	}
}