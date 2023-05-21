/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sigquit_in_execution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:03:44 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 13:06:59 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

void	handle_sigquit_in_execution(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 1);
}
