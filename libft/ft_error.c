#include "libft.h"

void	ft_error(const char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);	
}
