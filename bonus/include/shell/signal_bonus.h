/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:16:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:11:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_BONUS_H
# define SIGNAL_BONUS_H

void	handle_sigint(int sig);
void	handle_sigint_in_execution(int sig);
void	set_signal_handler(void);

#endif