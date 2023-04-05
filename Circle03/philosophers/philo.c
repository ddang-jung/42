#include "main.h"

void	philo_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->m_print);
	printf("%lld\t", get_time() - philo->info->start_time);
	printf("%d %s\n", philo->philo_i, msg);
	pthread_mutex_unlock(&philo->info->m_print);
}

void	routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	pthread_mutex_lock(&philo->m_philo_last_eat_time);
	philo->philo_last_eat_time = get_time();
	pthread_mutex_unlock(&philo->m_philo_last_eat_time);
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
		philo->philo_eat_count++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (philo->philo_eat_count >= philo->info->must_eat_times)
		{
			pthread_mutex_lock(&philo->info->m_full);
			philo->info->full++;
			pthread_mutex_unlock(&philo->info->m_full);
			return ;
		}
		philo_print(philo, "is sleeping");
		my_sleep(philo->info->time_to_sleep);
		philo_print(philo, "is thinking");
	}
}
