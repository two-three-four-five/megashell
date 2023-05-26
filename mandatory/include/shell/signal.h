/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:16:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/21 15:08:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	handle_sigint(int sig);
void	handle_sigint_in_execution(int sig);
void	set_signal_handler(void);

#endif