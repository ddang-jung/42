#include "main.h"

int	check_arg(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (ERROR);
	i = 0;
	while (++i < ac)
	{
		if (av[i] == NULL || *av[i] == '\0')
			return (ERROR);
		if (ft_atoi(av[i]) <= 0)
			return (ERROR);
	}
	return (OK);
}
