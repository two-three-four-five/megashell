/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:53:24 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:35:58 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "shell/type.h"

enum e_pipe_fd
{
	READ_FD = 0,
	WRITE_FD = 1
};

int		execute(t_tree *node, t_dict *env);
t_list	*split_path(char *path);
void	substitute_command_tree(t_tree *ptree, t_dict *env);
t_bool	is_builtin_cmd(char *cmd);
int		execute_cmd(t_tree *tree, t_dict *env);
int		execute_subshell(t_tree *tree, t_dict *env);
int		execute_and_if(t_tree *tree, t_dict *env);
int		execute_or_if(t_tree *tree, t_dict *env);
int		execute_pipe(t_tree *tree, t_dict *env);
int		execute_builtin(char **argv, char **envp);

#endif