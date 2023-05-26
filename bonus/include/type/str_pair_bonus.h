/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pair_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:36:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:11:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_PAIR_BONUS_H
# define STR_PAIR_BONUS_H

typedef struct s_str_pair	t_str_pair;

struct s_str_pair
{
	char	*s1;
	char	*s2;
};

void		del_str_pair(void *ptr);
void		*dup_str_pair_s1(void *ptr);
void		*dup_str_pair(void *ptr);
t_str_pair	*new_str_pair(char *s1, char *s2);
void		print_str_pair(void *ptr);

#endif