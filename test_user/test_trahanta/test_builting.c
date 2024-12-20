
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>



void ms_echo(char **av)
{
    int i;
    int j;
    j = 2;
    char c;
    while(av[j] != NULL)
	{
		i = 0;
		while(av[j][i] != '\0')
		{
			c = av[j][i];
			printf("%c", c);
			i++;
		}
		printf(" ");
		j++;
	}
}

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