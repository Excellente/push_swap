/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 08:48:28 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/10 10:52:02 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef	struct	s_read
{
	int		i;
	int		ret;
	int		last;
	int		index;
	char	buff[BUFF_SIZE + 1];
}				t_read;

int				ft_issempty(char *tmp);
int				ft_last_buff(t_read *r, char **line);
int				get_next_line(const int fd, char **line);
void			ft_reset(int *i, int *j);

#endif
