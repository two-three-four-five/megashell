/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:20:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 16:03:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell/signal.h"

void	set_signal_handler(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
