/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoperator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:27:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 22:28:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isoperator(int c)
{
	if ((char)c == '|' || (char)c == '&' || (char)c == ';' || \
		(char)c == '(' || (char)c == ')' || (char)c == '<' || \
		(char)c == '>')
		return (1);
	else
		return (0);
}
