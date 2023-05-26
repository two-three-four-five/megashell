/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter_token_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:45:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "type_bonus.h"
#include "shell_bonus.h"

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
		else if (!quote && s[0] == '$' && s[1] == '?')
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
		if (!dquote && s[idx] == '\'')
			quote = !quote;
		else if (!quote && s[idx] == '\"')
			dquote = !dquote;
		if (!quote && s[idx] == '$' && \
			(ft_isalpha(s[idx + 1]) || s[idx + 1] == '_'))
			return (idx);
		else if (!quote && s[idx] == '$' && s[idx + 1] == '?')
			return (idx);
		idx++;
	}
	return (-1);
}

static char	*get_identifier(char *s)
{
	int		len;

	len = 1;
	if (s[len] == '?')
		return (ft_substr(s, 0, 2));
	while (ft_isalnum(s[len]) || s[len] == '_')
		len++;
	return (ft_substr(s, 0, len));
}

static char	*expand_initial_parameter(char *s, t_dict *env)
{
	char	*key;
	char	*value;
	char	*new_token;
	int		i;
	int		len;

	i = get_identifier_idx(s);
	key = get_identifier(s + i);
	len = ft_strlen(s) - ft_strlen(key);
	if (!ft_strcmp(key, "$?"))
		value = ft_itoa(g_exit_status);
	else
		value = get_dict_value(env->next, key + 1);
	if (value)
		len += ft_strlen(value);
	new_token = (char *)ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(new_token, s, i + 1);
	if (value)
		ft_strlcat(new_token, value, len + 1);
	ft_strlcat(new_token, s + i + ft_strlen(key), len + 1);
	if (!ft_strcmp(key, "$?"))
		free(value);
	free(key);
	return (new_token);
}
