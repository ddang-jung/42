#include "main.h"

void	philo_print(t_philo *philo, char *msg)
{
	long long	timestamp;

	timestamp = get_time() - philo->info->start_time;
	pthread_mutex_lock(philo->m_print);
	printf("%lld\t %d %s\n", timestamp, philo->index, msg);
	pthread_mutex_unlock(philo->m_print);
}

void	pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	philo_print(philo, "has taken a fork");
}

void	count_eat(t_philo *philo)
{
	philo->count++;
	if (philo->count == philo->info->must_eat_times)
	{
		pthread_mutex_lock(philo->m_full);
		philo->info->full_philo++;
		pthread_mutex_unlock(philo->m_full);
	}
}

void	eat(t_philo *philo)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(philo->m_eat);
	philo->last_eat = now;
	pthread_mutex_unlock(philo->m_eat);
	philo_print(philo, "is eating");
	if (philo->info->must_eat_times != -1)
		count_eat(philo);
	my_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleep_and_think(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	my_sleep(philo->info->time_to_sleep);
	philo_print(philo, "is thinking");
}
