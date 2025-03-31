
#include "minishell.h"

bool	is_not_word(char c)
{
	return (is_space(c) || c == '|' || c == '>' || c == '<');
}
