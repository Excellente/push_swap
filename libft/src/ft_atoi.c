/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:23:21 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 12:59:33 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int num;
	int neg;
	int index;

	num = 0;
	neg = 0;
	index = 0;
	while ((str[index] >= 7 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == 45)
		neg = 1;
	if (str[index] == 45 || str[index] == 43)
		index++;
	while (str[index] >= 48 && str[index] <= 57)
	{
		num *= 10;
		num +=  (int)(str[index] - '0');
		index++;
	}
	if (neg == 1)
		return (-num);
	else
		return (num);
}
