/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:20:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell/signal_bonus.h"

void	set_signal_handler(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
