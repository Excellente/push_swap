/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:37:57 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 13:42:59 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "libft.h"
# define ERROR '0'
typedef	struct s_stack	t_stack;
typedef	struct s_check	t_check;
struct	s_config
{
	int	is_sorted;
	int	is_partially;
	int	is_unsorted;
	int	is_reverse;
}		t_config;

struct	s_check
{
	char	*line;
	char	**ops;
	char	**elem;
};

struct	s_stack
{
	int		size;
	int		max_elem;
	int		*elements;
	char	name[10];
};

int		ft_top(t_stack *p);
int		ft_pop(t_stack *p);
int		ft_isfull(t_stack *p);
int		ft_numcmp(t_stack *p);
int		ft_isempty(t_stack *p);
int		ft_issorted(t_stack *p);
int		ft_isrsorted(t_stack *p);
int		ft_can_rotate(t_stack *p);
int		ft_can_rrotate(t_stack *p);
int		ft_can_rr(t_stack *a, t_stack *b);
int		ft_can_rrr(t_stack *a, t_stack *b);
void	ft_putop(char *o);
void	ft_rotate(t_stack *p);
void	ft_rrotate(t_stack *p);
void	ft_print_error(char *e);
void	ft_sort(t_stack *p);
void	ft_error_repeat(char **s);
void	ft_push(int e, t_stack *p);
void	ft_check_config(t_stack *p);
void	ft_swap(t_stack *p, char *o);
void	ft_validate_args(int c, char **s);
void	ft_check_args(int argc, char **a);
void	ft_print_stack(t_stack *a, char *n);
void	ft_refill_a(t_stack *a, t_stack *b);
void	ft_swaping(t_stack *a, t_stack *b);
void	ft_rotation(t_stack *a, t_stack *b);
void	ft_init_stack(t_stack **p, int ac, char **a);
void	ft_push_in(char *o, char *c, t_stack *a, t_stack *b);
void	ft_swap_in(char *o, char *c, t_stack *a, t_stack *b);
void	ft_rot_stack(char *o, char *c, t_stack *a, t_stack *b);
t_stack	*ft_new_stack(int max);

#endif
