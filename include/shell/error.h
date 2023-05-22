/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:36:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 17:23:43 by gyoon            ###   ########.fr       */
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
	FILE_ERROR = 0x0020,
	PERMISSION_DENIED = 0x0021,
	IS_A_DIRECTORY = 0x0023,
	AMBIGUOUS_REDIRECT = 0x0025,
	NO_SUCH_FILE_OR_DIRECTORY = 0x0027,
};

void	raise_exit(void);
void	raise_syntax_error(int errno, char *token, char c1, char c2);
void	raise_file_error(int errno, char *filename);

#endif