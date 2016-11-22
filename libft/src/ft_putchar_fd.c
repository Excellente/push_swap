#include "libft.h"

void	ft_putchar_fd(int fd, int c)
{
	write(fd, &c, 1);
}
