#include "main.h"

void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->index & 1)
		usleep(5000);
	while (1)
	{
		pickup(philo);
		eat(philo);
		sleep_and_think(philo);
	}
	return (NULL);
}

int	check_dead(t_philo *philo, long long now)
{	
	pthread_mutex_lock(philo->m_eat);
	if (now - philo->last_eat >= philo->info->time_to_die)
	{
		pthread_mutex_lock(philo->m_print);
		printf("%lld\t %d died\n", now - philo->info->start_time, philo->index);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->m_eat);
	return (FALSE);
}

int	check_full(t_info *info)
{
	pthread_mutex_lock(&info->m_full);
	if (info->full_philo == info->num_philo)
	{
		pthread_mutex_lock(&info->m_print);
		return (TRUE);
	}
	pthread_mutex_unlock(&info->m_full);
	return (FALSE);
}

void	monitor(t_info *info)
{
	int			i;
	long long	now;

	while (1)
	{
		i = -1;
		now = get_time();
		while (++i < info->num_philo)
			if (check_dead(&info->philo[i], now) == TRUE)
				return ;
		if (info->must_eat_times != -1)
			if (check_full(info) == TRUE)
				return ;
	}
}

int	run(t_info *info)
{
	t_philo	*philo;
	int		i;

	info->start_time = get_time();
	i = -1;
	while (++i < info->num_philo)
	{
		philo = &info->philo[i];
		philo->last_eat = get_time();
		if (pthread_create(&philo->thread, 0, routine, philo))
			return (ERROR);
	}
	monitor(info);
	return (OK);
}
