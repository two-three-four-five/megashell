/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:35:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_BONUS_H
# define DICT_BONUS_H

# include "libft.h"
# include "type/str_pair_bonus.h"

// dictionary : lst of str_pairs
typedef struct s_list		t_dict;

char		*get_dict_value(t_dict *dict, char *key);
t_bool		has_dict_key(t_dict *dict, char *key);
t_bool		reassign_dict_value(t_dict *dict, char *key, char *value);

#endif