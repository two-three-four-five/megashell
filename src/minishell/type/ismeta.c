/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismeta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:26:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 16:55:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"

int	ismeta(int c)
{
	if (isdelimeter(c) || isoperator(c))
		return (1);
	else
		return (0);
}