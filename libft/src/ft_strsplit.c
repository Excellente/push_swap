/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:36:24 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 11:52:20 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_word_count(char *s, char c)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

int		ft_get_word_len(char *s, char c, int index)
{
	int	end;
	int	start;
	int	word_len;

	end = 0;
	word_len = 0;
	start = index;
	while (s[index] != c && s[index])
	{
		index++;
		end = index;
	}
	word_len = end - start;
	return (word_len);
}

int		ft_hasword(char *s, char c, int dec, t_index *i)
{
	if (dec == 1)
	{
		if (ft_get_word_count(s, c))
			return (1);
		return (0);
	}
	else
	{
		i->i = 0;
		i->j = 0;
		i->sptr = 0;
		i->word = 0;
		return (-1);
	}
}

void	ft_get_word(t_index *var, char c, char *str)
{
	while (str[var->i] != c && str[var->i] != '\0')
	{
		var->word[var->index] = str[var->i];
		var->i++;
		var->index++;
	}
}

char	**ft_strsplit(char *str, char c)
{
	t_index	var;

	ft_hasword(str, c, 0, &var);
	var.sptr = (char **)malloc(sizeof(char *) *
			(ft_get_word_count(str, c) + 1));
	if (ft_hasword(str, c, 1, &var))
	{
		while (str[var.i] != '\0')
		{
			var.index = 0;
			while (str[var.i] == c && str[var.i] != '\0')
				var.i++;
			if (str[var.i] != '\0')
			{
				var.word = (char *)malloc(sizeof(char) *
						(ft_get_word_len(str, c, var.i) + 1));
				ft_get_word(&var, c, str);
				var.word[var.index] = '\0';
				var.sptr[var.j] = var.word;
				var.j++;
			}
		}
	}
	var.sptr[var.j] = 0;
	return (var.sptr);
}
