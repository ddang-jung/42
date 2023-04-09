#include "main.h"

int	check(int ac, char **av)
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

int	clean(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_detach(info->philo[i].thread))
			return (ERROR);
	}
	pthread_mutex_unlock(&info->m_eat);
	pthread_mutex_unlock(&info->m_full);
	pthread_mutex_unlock(&info->m_print);
	pthread_mutex_destroy(&info->m_eat);
	pthread_mutex_destroy(&info->m_full);
	pthread_mutex_destroy(&info->m_print);
	return (OK);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (check(ac, av) == ERROR)
		return (error("Unvalid Arguments."));
	if (init(&info, ac, av) == ERROR)
		return (error("init() Error."));
	if (run(&info) == ERROR)
		return (error("run() Error."));
	if (clean(&info) == ERROR)
		return (error("clean() Error."));
	return (OK);
}
