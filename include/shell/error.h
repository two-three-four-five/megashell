/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:36:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/15 20:38:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_errno
{
	SYNTAX_ERROR = 0x0010,
	UNDEFINED_TOKEN = 0x0011,
	MISSING_TOKEN = 0x0013,
	UNEXPECTED_TOKEN = 0x0015,
};

void	raise_syntax_error(int errno, char *token, char c1, char c2);

#endif