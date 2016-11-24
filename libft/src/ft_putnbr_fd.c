#include "libft.h"

void	ft_putnbr_fd(int fd, int nbr)
{
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd(fd, -nbr);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(fd, nbr / 10);
		ft_putnbr_fd(fd, nbr % 10);
	}
	else
		ft_putchar_fd(fd, nbr + '0');
}
