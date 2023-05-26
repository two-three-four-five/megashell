/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_BONUS_H
# define TYPE_BONUS_H

# include "libft.h"
# include "type/bool_bonus.h"
# include "type/dict_bonus.h"
# include "type/str_pair_bonus.h"
# include "type/string_bonus.h"
# include "type/tree_bonus.h"

int			isdelimeter(int c);
int			ismeta(int c);
int			isoperator(int c);
int			isquote(int c);

#endif