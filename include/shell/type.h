/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:11:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "libft.h"

typedef enum e_bool			t_bool;

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

// dictionary : lst of str_pairs
typedef struct s_list		t_dict;
typedef struct s_str_pair	t_str_pair;

struct s_str_pair
{
	char	*s1;
	char	*s2;
};

// tree
typedef struct s_tree		t_tree;

struct s_tree
{
	void			*content;
	struct s_tree	*left;
	struct s_tree	*right;
};

t_tree		*ft_treenew(void *content);
void		ft_treeadd_leftend(t_tree **tree, t_tree *new);
void		ft_treeadd_rightend(t_tree **tree, t_tree *new);
void		ft_treeclear(t_tree **tree, void (*del)(void *));

int			isdelimeter(int c);
int			ismeta(int c);
int			isoperator(int c);
int			isquote(int c);

void		del_str_pair(void *ptr);
t_str_pair	*new_str_pair(char *s1, char *s2);
void		print_str_pair(void *ptr);

char		*get_dict_value(t_dict *dict, char *key);

#endif