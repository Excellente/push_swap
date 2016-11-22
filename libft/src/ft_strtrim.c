/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:36:49 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/22 11:58:35 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_word(const char *str)
{
	int index;

	index = 0;
	while (str[index] == '\n' || str[index] == '\t' || str[index] != ' ')
		index++;
	return (index);
}

int		ft_last_word(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	while (str[index] == '\n' || str[index] == '\t' || str[index] != ' ')
		index--;
	return (index);
}

char	*ft_strtrim(const char *str)
{
	int		i;
	int		end;
	int		begin;
	int		index;
	char	*res;

	i = 0;
	index = 0;
	res = NULL;
	if (str == NULL)
		return (NULL);
	end = ft_last_word(str);
	begin = ft_first_word(str);
	res = (char *)malloc((sizeof(*res) * ft_strlen(str)) + 1);
	while (str[index] != '\0')
	{
		if (index >= begin && index <= end)
			res[i++] = str[index];
		index++;
	}
	res[i] = '\0';
	return (res);
}
