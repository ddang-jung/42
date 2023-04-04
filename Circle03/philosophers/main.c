#include "main.h"

// TODO 철학자 1명일때 예외처리
// TODO ./philo 310 200 100 -> 죽어야되는데 안죽음

int	main(int ac, char **av)
{
	t_info	info;

	if (check_arg(ac, av) == ERROR)
		return (1);
	if (init_info(&info, ac, av) == ERROR)
		return (1);
	if (run_philo(&info) == ERROR)
		return (1);
	if (clean(&info) == ERROR)
		return (1);
	return (0);
}