/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:28:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 16:28:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isquote(int c)
{
	if ((char)c == '\'' || (char)c == '\"')
		return (1);
	else
		return (0);
}