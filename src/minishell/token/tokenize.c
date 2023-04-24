/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/24 16:40:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;
	char	*token;

	lst = NULL;
	while (true)
	{
		node = ft_lstnew(get_next_token(s));
		if (!node || !node.content)
			break ;
		ft_lstadd_back(&lst, node);
	}
	return (lst);
}
