/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_BONUS_H
# define ENVP_BONUS_H

# include "type_bonus.h"

t_dict	*get_envp_dict(char **envp);
char	**get_envp(t_dict *env);

#endif