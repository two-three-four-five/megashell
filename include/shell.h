/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:44:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:07:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "shell/command.h"
# include "shell/envp.h"
# include "shell/error.h"
# include "shell/input.h"
# include "shell/signal.h"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYN "\033[0;36m"
# define BOLD "\033[0;37m"
# define END "\033[0;0m"

extern int	g_exit_status;

void	execute_shell(char **envp);

#endif