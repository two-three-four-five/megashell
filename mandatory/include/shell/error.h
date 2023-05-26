/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:36:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:58:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define SYNTAX_ERROR 0x0010
# define UNDEFINED_TOKEN 0x0011
# define MISSING_TOKEN 0x0013
# define UNEXPECTED_TOKEN 0x0015

# define FILE_ERROR 0x0020
# define AMBIGUOUS_REDIRECT 0x0021
# define COMMAND_ERROR 0x0040
# define IS_A_DIRECTORY 0x0063
# define COMMAND_NOT_FOUND 0x0067

# define CD_ERROR 0x0080
# define HOME_NOT_SET 0x0081
# define OLDPWD_NOT_SET 0x0083
# define PERMISSION_DENIED 0x00A1
# define NOT_A_DIRECTORY 0x00A3
# define NO_SUCH_FILE_OR_DIRECTORY 0x00A5
# define TOO_MANY_ARGUMENTS 0x00A7

# define NUMERIC_ARGUMENT_REQUIRED 0x0101

# define MSG_DISH "dish: "
# define MSG_NO_SUCH_FILE_OR_DIRECTORY ": No such file or directory"
# define MSG_IS_A_DIRECTORY ": Is a directory"
# define MSG_PERMISSION_DENIED ": Permission denied"
# define MSG_AMBIGUOUS_REDIRECT ": ambiguous redirect"
# define MSG_COMMAND_NOT_FOUND ": command not found"

int		raise_cd_error(int errno, char *arg);
int		raise_cmd_error(int errno, char *cmd);
void	raise_exit_error(int errno, char *arg);
void	raise_exit(void);
void	raise_file_error(int errno, char *filename);
void	raise_redirect_error(char *token);
void	raise_syntax_error(int errno, char *token, char c1, char c2);

#endif
