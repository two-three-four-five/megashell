/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:52:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 01:06:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# define FT_LLONG_MAX 9223372036854775807LL

void		del_strp(char **strp);
long long	ft_atoll(char *str);
int			ft_strcmp(const char *s1, const char *s2);

#endif
