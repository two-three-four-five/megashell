/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:28:49 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 00:29:06 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_strp(char **strp)
{
	int	idx;

	idx = 0;
	while (strp[idx])
		free(strp[idx]);
	free(strp);
}
