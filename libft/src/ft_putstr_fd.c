#include "libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar_fd(fd, str[index]);
		index++;
	}
}
