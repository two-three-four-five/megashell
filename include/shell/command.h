/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:53:24 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 09:26:06 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "type.h"

enum e_pipe_fd
{
	READ_FD = 0,
	WRITE_FD = 1
};

int		execute_echo(t_tree *tree, t_dict *env);
int		execute_env(t_tree *tree, t_dict *env);
int		execute_unset(t_tree *tree, t_dict *env);

int		redirect_fd(t_tree *tree);

int		execute_and_if(t_tree *tree, t_dict *env);
int		execute_builtin(t_tree *tree, t_dict *env);
int		execute_cmd(t_tree *tree, t_dict *env);
int		execute_in_child(t_tree *tree, t_dict *env);
int		execute_or_if(t_tree *tree, t_dict *env);
int		execute_pipe(t_tree *tree, t_dict *env);
int		execute_subshell(t_tree *tree, t_dict *env);


t_bool	is_directory(char *filename);
t_bool	is_executable(char *filename);
t_bool	is_file_exist(char *filename);
char	**get_argv(t_tree *tree);
int		get_exit_status(int status);
t_bool	is_builtin_cmd(char *cmd);

int		execute(t_tree *node, t_dict *env);
void	substitute_command_tree(t_tree *ptree, t_dict *env);

#endif
