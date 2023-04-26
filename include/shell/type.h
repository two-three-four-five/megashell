/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 22:36:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

int	isdelimeter(int c);
int	ismeta(int c);
int	isoperator(int c);
int	isquote(int c);

#endif