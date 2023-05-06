/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/06 17:27:40 by gyoon            ###   ########.fr       */
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


int			isdelimeter(int c);
int			ismeta(int c);
int			isoperator(int c);
int			isquote(int c);

void		del_str_pair(void *ptr);
t_str_pair	*new_str_pair(char *s1, char *s2);

char		*get_dict_value(t_dict *dict, char *key);

#endif