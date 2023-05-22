/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:45:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"
#include <stdlib.h>

static int	count_parameter(char *s);
static int	get_identifier_idx(char *s);
static char	*get_identifier(char *s);
static char	*expand_initial_parameter(char *s, t_dict *env);

char	*expand_parameter_token(char *token, t_dict *env)
{
	int		var_cnt;
	int		i;
	char	*prev;
	char	*new_token;

	prev = ft_strdup(token);
	var_cnt = count_parameter(prev);
	if (!var_cnt)
		return (prev);
	i = 0;
	while (i < var_cnt)
	{
		new_token = expand_initial_parameter(prev, env);
		free(prev);
		prev = new_token;
		i++;
	}
	return (new_token);
}

static int	count_parameter(char *s)
{
	t_bool	quote;
	t_bool	dquote;
	int		var_cnt;

	quote = FALSE;
	dquote = FALSE;
	var_cnt = 0;
	while (*s)
	{
		if (!dquote && *s == '\'')
			quote = !quote;
		else if (!quote && *s == '\"')
			dquote = !dquote;
		if (!quote && *s == '$' && (ft_isalpha(s[1]) || s[1] == '_'))
			var_cnt++;
		s++;
	}
	return (var_cnt);
}

static int	get_identifier_idx(char *s)
{
	t_bool	quote;
	t_bool	dquote;
	int		idx;

	quote = FALSE;
	dquote = FALSE;
	idx = 0;
	while (s[idx])
	{
		if (!dquote && *s == '\'')
			quote = !quote;
		else if (!quote && *s == '\"')
			dquote = !dquote;
		if (!quote && s[idx] == '$' && \
			(ft_isalpha(s[idx + 1]) || s[idx + 1] == '_'))
			return (idx);
		idx++;
	}
	return (-1);
}

static char	*get_identifier(char *s)
{
	int		len;

	len = 1;
	while (ft_isalnum(s[len]) || s[len] == '_')
		len++;
	return (ft_substr(s, 0, len));
}

static char	*expand_initial_parameter(char *s, t_dict *env)
{
	char	*key;
	char	*new_token;
	int		i;
	int		len;

	i = get_identifier_idx(s);
	key = get_identifier(s + i);
	len = ft_strlen(s) - ft_strlen(key);
	if (get_dict_value(env, key + 1))
		len += ft_strlen(get_dict_value(env, key + 1));
	new_token = (char *)ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(new_token, s, i + 1);
	if (get_dict_value(env, key + 1))
		ft_strlcat(new_token, get_dict_value(env, key + 1), len + 1);
	ft_strlcat(new_token, s + i + ft_strlen(key), len + 1);
	free(key);
	return (new_token);
}
