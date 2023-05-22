/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:44:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 16:58:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "shell/command.h"
# include "shell/envp.h"
# include "shell/error.h"
# include "shell/input.h"
# include "shell/signal.h"

extern int	g_exit_status;

void	execute_shell(char **envp);

#endif