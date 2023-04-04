#include "main.h"

pthread_mutex_t	*init_fork(int num)
{
	pthread_mutex_t	*init;
	int				i;

	init = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!init)
		return (NULL);
	i = -1;
	while (++i < num)
		if (pthread_mutex_init(&init[i], NULL))
			return (NULL);
	return (init);
}

t_philo	*init_philo(t_info *info)
{
	t_philo	*init;
	int		i;

	init = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!init)
		return (NULL);
	i = -1;
	while (++i < info->num_philo)
	{
		init[i].philo_i = i + 1;
		init[i].philo_status = NORM;
		init[i].philo_eat_count = 0;
		init[i].philo_last_eat_time = 0;
		init[i].l_fork = &info->fork[i];
		if (i == 0)
			init[i].r_fork = &info->fork[info->num_philo - 1];
		else
			init[i].r_fork = &info->fork[i - 1];
		if (pthread_mutex_init(&init[i].m_philo_eat_count, NULL))
			return (NULL);
		if (pthread_mutex_init(&init[i].m_philo_last_eat_time, NULL))
			return (NULL);
		init[i].info = info;
	}
	return (init);
}

int	check_valid(int ac, t_info *info)
{
	if (info->num_philo <= 0 || \
		info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || \
		info->time_to_sleep <= 0)
		return (ERROR);
	if (ac == 5 && info->must_eat_times != -1)
		return (ERROR);
	if (ac == 6 && info->must_eat_times <= 0)
		return (ERROR);
	if (!info->fork)
		return (ERROR);
	if (!info->philo)
		return (ERROR);
	return (OK);
}

int	init_info(t_info *info, int ac, char **av)
{
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat_times = -1;
	if (ac == 6)
		info->must_eat_times = ft_atoi(av[5]);
	info->status = NORM;
	info->start_time = 0;
	info->fork = init_fork(info->num_philo);
	info->philo = init_philo(info);
	if (pthread_mutex_init(&info->m_status, NULL))
		return (ERROR);
	if (pthread_mutex_init(&info->m_print, NULL))
		return (ERROR);
	return (check_valid(ac, info));
}
