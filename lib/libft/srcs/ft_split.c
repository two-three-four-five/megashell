/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:41 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/25 23:45:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] == c)
			return (len);
		len++;
	}
	return (len);
}

static int	get_word_count(char const *str, char c)
{
	int	word_count;

	word_count = 0;
	while (*str)
	{
		if (get_word_len(str, c) != 0)
		{
			word_count++;
			str += get_word_len(str, c);
		}
		else
			str++;
	}
	return (word_count);
}

static char	*get_word(char const *str, int len)
{
	char	*word;
	int		idx;

	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (0);
	idx = 0;
	while (idx < len)
		word[idx++] = *str++;
	return (word);
}

static void	free_split(char **ret)
{
	int	idx;

	idx = 0;
	while (ret[idx])
		free(ret[idx++]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ridx;

	if (get_word_count(s, c) == 0)
		return (0);
	ret = (char **)ft_calloc(get_word_count(s, c) + 1, sizeof(char *));
	if (!ret)
		return (0);
	ridx = 0;
	while (*s)
	{
		if (get_word_len(s, c) != 0)
		{
			ret[ridx++] = get_word(s, get_word_len(s, c));
			if (!(ret[ridx - 1]))
			{
				free_split(ret);
				return (0);
			}
			s += get_word_len(s, c);
		}
		else
			s++;
	}
	return (ret);
}
