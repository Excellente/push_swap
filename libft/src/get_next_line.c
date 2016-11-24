/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 08:40:05 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 15:45:27 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int		ft_issempty(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	if (i > 0)
		return (1);
	return (0);
}

int		ft_last_buff(t_read *r, char **line)
{
	ft_strclr(*line);
	while (r->buff[r->last] == '\n')
		r->last++;
	while (r->buff[r->last] != '\n' && r->buff[r->last] != '\0')
		line[0][r->i++] = r->buff[r->last++];
	if (r->buff[r->last] == '\n')
		return (1);
	return (0);
}

int		ft_read_line(int fd, t_read *r, char **line)
{
	ft_reset(&r->index, &r->last);
	while (r->buff[r->index] != EOF &&
	(r->ret = read(fd, r->buff, BUFF_SIZE)) > 0)
	{
		ft_reset(&r->last, &r->index);
		while (r->buff[r->index] != '\0' && r->buff[r->index] != EOF)
			line[0][r->i++] = r->buff[r->index++];
	}
	r->last = r->index;
	line[0][r->i] = '\0';
	return (r->last);
}

int		get_next_line(const int fd, char **line)
{
	static	t_read	read;

	//if (fd == STDIN_FILENO)
		//ft_strclr(read.buff);
	read.ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = (char *)malloc(sizeof(char) * 2048);
	ft_reset(&read.i, &read.ret);
	read.buff[BUFF_SIZE] = '\0';
	if (read.buff[read.last] != '\0')
		if ((read.ret = ft_last_buff(&read, line)) == 1)
			return (1);
	ft_strclr(read.buff);
	read.last = ft_read_line(fd, &read, line);
	if (read.ret > 0 && read.buff[read.last] == '\n')
		return (1);
	return (read.ret);
}
