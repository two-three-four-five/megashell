/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:38:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/27 22:08:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/string.h"

long long	ft_atoll(char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
		sign = -(*str++ - 44);
	while (*str >= '0' && *str <= '9')
	{
		if (sign > 0)
		{
			if ((result > FT_LLONG_MAX / 10) || \
				(result == FT_LLONG_MAX / 10 && *str - '0' > FT_LLONG_MAX % 10))
				return (-1);
		}
		else
		{
			if ((result > FT_LLONG_MAX / 10) || \
				(result == FT_LLONG_MAX / 10 && *str - '0' > 8))
				return (-1);
		}
		result = result * 10 + *str++ - '0';
	}
	return (sign * result);
}
