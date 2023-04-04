#include "main.h"

int	handler(t_info *info, t_philo *philo, int flag)
{
	if (flag == DEAD)
	{
		pthread_mutex_unlock(&philo->m_philo_last_eat_time);
		pthread_mutex_lock(&info->m_status);
		info->status = DEAD;
		philo_print(philo, "died");
		pthread_mutex_unlock(&info->m_status);
		return (1);
	}
	if (flag == FULL)
	{
		pthread_mutex_lock(&info->m_status);
		info->status = FULL;
		pthread_mutex_unlock(&info->m_status);
		return (1);
	}
	return (OK);
}

int	monitor(t_info *info)
{
	t_philo	*philo;
	int		full;
	int		i;

	full = 0;
	i = -1;
	while (++i < info->num_philo)
	{
		philo = &info->philo[i];
		pthread_mutex_lock(&philo->m_philo_last_eat_time);
		if (philo->philo_last_eat_time - get_time() >= info->time_to_die)
			return (handler(info, philo, DEAD));
		pthread_mutex_unlock(&philo->m_philo_last_eat_time);
		if (info->must_eat_times != -1)
		{
			pthread_mutex_lock(&philo->m_philo_eat_count);
			if (philo->philo_eat_count >= info->must_eat_times)
				full++;
			pthread_mutex_unlock(&philo->m_philo_eat_count);
		}
	}
	if (info->must_eat_times != -1 && (full == info->num_philo))
		return (handler(info, philo, FULL));
	return (OK);
}

int	run_philo(t_info *info)
{
	int		i;

	info->start_time = get_time();
	i = -1;
	while (++i < info->num_philo)
		if (create(&info->philo[i]) == ERROR)
			return (ERROR);
	while (1)
		if (monitor(info))
			return (OK);
}
