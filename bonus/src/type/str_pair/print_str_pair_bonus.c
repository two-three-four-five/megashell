/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_pair_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:05:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type_bonus.h"

void	print_str_pair(void *ptr)
{
	t_str_pair	*str_pair;

	str_pair = (t_str_pair *)ptr;
	if (str_pair->s2)
		printf("%s=%s\n", str_pair->s1, str_pair->s2);
}
