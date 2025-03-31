#include "minishell.h"

volatile sig_atomic_t	g_signal = 0;

int	main_loop(t_data *minishell, char *input)
{
	while (1)
	{
		ft_signal();
		minishell->token = NULL;
		input = readline("$> ");
		if (g_signal != 0)
		{
			minishell->state = g_signal;
			g_signal = 0;
			continue ;
		}
		if (!input)
			break ;
		if (!*input)
			continue ;
		else
			add_history(input);
		exec(minishell->command, minishell);
		(ft_tokenclear(&minishell->token),
			ft_commandclear(&minishell->command));
		free((minishell->token = 0, minishell->command = 0, NULL));
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char		*input;
	t_data	minishell;

	input = NULL;
	if (!isatty(0))
		return (printf("tty required!!\n"), 1);
	(void)ac;
	(void)av;
	minishell = (t_data){0};
	main_loop(&minishell, input);
	minishell.state = 0;
	ft_envclear(&minishell.env);
	return (0);
}
