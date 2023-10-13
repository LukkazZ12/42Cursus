/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <lucade-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:04:09 by lucade-s          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:49 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mark_metachar_inside_quotes(char *prompt)
{
	int		i;
	char	c;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\"' || prompt[i] == '\'')
		{
			c = prompt[i];
			i++;
			while (prompt[i] && prompt[i] != c)
			{
				if (prompt[i] == '|')
					prompt[i] = PIPE_QUOTES;
				else if (prompt[i] == '<')
					prompt[i] = L_RDCT_QUOTES;
				else if (prompt[i] == '>')
					prompt[i] = R_RDCT_QUOTES;
				i++;
			}
		}
		if (prompt[i] != '\0')
			i++;
	}
}

static void	mark_metachar_dollar_and_tilde(char *prompt, int i)
{
	if (prompt[i] == '$' && prompt[i + 1] != '$'
		&& prompt[i + 1] && !ft_iswhitespace(prompt[i + 1]))
		prompt[i] = DOLLAR_VAR;
	else if (prompt[i] == '~' && (i == 0 || ft_iswhitespace(prompt[i - 1])
			|| prompt[i - 1] == '=') && (ft_iswhitespace(prompt[i + 1])
			|| !prompt[i + 1] || prompt[i + 1] == '/' || prompt[i + 1] == ':'))
		prompt[i] = TILDE_VAR;
}

static void	mark_metachar_dollar(char *prompt, int i)
{
	if (prompt[i] == '$' && prompt[i + 1] != '$' && prompt[i + 1]
		&& !ft_iswhitespace(prompt[i + 1]) && prompt[i + 1] != '\"')
		prompt[i] = DOLLAR_VAR;
}

void	find_metachar(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\'')
		{
			i++;
			while (prompt[i] && prompt[i] != '\'')
				i++;
		}
		else if (prompt[i] == '\"')
		{
			i++;
			while (prompt[i] && prompt[i] != '\"')
			{
				mark_metachar_dollar(prompt, i);
				i++;
			}
		}
		else
			mark_metachar_dollar_and_tilde(prompt, i);
		if (prompt[i] != '\0')
			i++;
	}
}

void	change_metachar_back(t_token *token_list)
{
	int		i;
	int		j;
	t_token	*aux;

	aux = token_list;
	while (aux)
	{
		i = 0;
		while (aux->token[i])
		{
			j = 0;
			while (aux->token[i][j])
			{
				if (aux->token[i][j] == PIPE_QUOTES)
					aux->token[i][j] = '|';
				else if (aux->token[i][j] == L_RDCT_QUOTES)
					aux->token[i][j] = '<';
				else if (aux->token[i][j] == R_RDCT_QUOTES)
					aux->token[i][j] = '>';
				j++;
			}
			i++;
		}
		aux = aux->next;
	}
}
