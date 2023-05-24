/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:38:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 21:40:57 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef struct s_tree	t_tree;

struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
};

void		ft_treeadd_rightend(t_tree **tree, t_tree *node);
void		ft_treeadd_leftend(t_tree **tree, t_tree *node);
void		ft_treeclear(t_tree **tree, void (*del)(void *));
int			ft_treeleftsize(t_tree *tree);
t_tree		*ft_treenew(void *content);
void		print_tree(t_tree *tree, char *prefix, int is_left);

#endif
