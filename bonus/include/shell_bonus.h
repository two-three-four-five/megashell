/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:44:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_BONUS_H
# define SHELL_BONUS_H

# include "shell/command_bonus.h"
# include "shell/envp_bonus.h"
# include "shell/error_bonus.h"
# include "shell/input_bonus.h"
# include "shell/signal_bonus.h"

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