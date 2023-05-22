/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_pair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:05:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:41:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type.h"

void	print_str_pair(void *ptr)
{
	t_str_pair	*str_pair;

	str_pair = (t_str_pair *)ptr;
	printf("%-30s | %s\n", str_pair->s1, str_pair->s2);
}
