/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:35:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:38:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "libft.h"
# include "type/str_pair.h"

// dictionary : lst of str_pairs
typedef struct s_list		t_dict;

char		*get_dict_value(t_dict *dict, char *key);

#endif