#include "main.h"

int	handler(t_info *info, t_philo *philo, int flag)
{
	if (flag == DEAD)
	{
		pthread_mutex_unlock(&philo->m_philo_last_eat_time);
		philo_print(philo, "died");
		pthread_mutex_lock(&info->m_status);
		info->status = DEAD;
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
	int		i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo = &info->philo[i];
		pthread_mutex_lock(&philo->m_philo_last_eat_time);
		if (get_time() - philo->philo_last_eat_time >= info->time_to_die)
			return (handler(info, philo, DEAD));
		pthread_mutex_unlock(&philo->m_philo_last_eat_time);
		if (info->must_eat_times != -1)
		{
			pthread_mutex_lock(&info->m_full);
			if (info->full == info->num_philo)
				return (handler(info, philo, FULL));
			pthread_mutex_lock(&info->m_full);
		}
	}
	return (OK);
}

int	run(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	info->start_time = get_time();
	while (++i < info->num_philo)
	{
		philo = &info->philo[i];
		philo->philo_last_eat_time = get_time(); // 이거 routine 안에서 한 번 더 하는데 왜 하는지 모르겠음
		if (pthread_create(&philo->thread, NULL, (void *)routine, philo))
			return (ERROR);
	}
	while (1)
		if (monitor(info))
			return (OK);
}
