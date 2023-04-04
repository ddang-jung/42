#include "main.h"

void	philo_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->m_print);
	printf("%lld\t", get_time() - philo->info->start_time);
	printf("%d %s\n", philo->philo_i, msg);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	count(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_philo_eat_count);
	philo->philo_eat_count++;
	pthread_mutex_unlock(&philo->m_philo_eat_count);
}

void	routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->philo_i % 2)
		my_sleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->info->m_status);
		if (philo->info->status != NORM)
		{
			pthread_mutex_unlock(&philo->info->m_status);
			return ;
		}
		pthread_mutex_unlock(&philo->info->m_status);
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, "has taken a fork");
		philo_print(philo, "is eating");
		my_sleep(philo->info->time_to_eat);
		pthread_mutex_lock(&philo->m_philo_last_eat_time);
		philo->philo_last_eat_time = get_time();
		pthread_mutex_unlock(&philo->m_philo_last_eat_time);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo_print(philo, "is sleeping");
		my_sleep(philo->info->time_to_sleep);
		philo_print(philo, "is thinking");
		if (philo->info->must_eat_times != -1)
			count(philo);
	}
}

int	create(t_philo *philo)
{
	philo->philo_last_eat_time = get_time();
	if (pthread_create(&philo->philo_thread, NULL, (void *)routine, philo))
		return (ERROR);
	return (OK);
}
