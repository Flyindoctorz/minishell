/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelgon <cgelgon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:57:55 by cgelgon           #+#    #+#             */
/*   Updated: 2025/02/11 15:09:52 by cgelgon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer_test.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
    run_lexer_test();
    return (0);
}