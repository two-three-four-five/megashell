/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:51:44 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"

static char	*ft_envjoin(t_str_pair *pair)
{
	const int	strsize = ft_strlen(pair->s1) + ft_strlen(pair->s2) + 2;
	char		*ret;

	ret = ft_calloc(strsize, sizeof(char));
	ft_strlcpy(ret, pair->s1, strsize);
	ft_strlcat(ret, "=", strsize);
	ft_strlcat(ret, pair->s2, strsize);
	return (ret);
}

char	**get_envp(t_dict *env)
{
	char	**envp;
	int		idx;

	envp = ft_calloc(ft_lstsize(env) + 1, sizeof(char *));
	idx = 0;
	while (env)
	{
		envp[idx++] = ft_envjoin(env->content);
		env = env->next;
	}
	return (envp);
}
