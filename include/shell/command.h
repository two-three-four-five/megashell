/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:53:24 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 15:48:51 by jinhchoi         ###   ########.fr       */
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
int		exec_cmd(t_tree *tree, t_dict *env);
int		exec_builtin(t_tree *node, t_dict *env);

#endif