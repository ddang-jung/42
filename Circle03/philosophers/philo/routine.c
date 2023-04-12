/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:17:39 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/04/11 21:08:48 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	pickup(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo_print(philo, "has taken a fork"))
		return (1);
	if (philo->info->num_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	pthread_mutex_lock(philo->r_fork);
	if (philo_print(philo, "has taken a fork"))
		return (1);
	return (0);
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

int	eat(t_philo *philo)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(philo->m_eat);
	philo->last_eat = now;
	pthread_mutex_unlock(philo->m_eat);
	if (philo_print(philo, "is eating"))
		return (1);
	if (philo->info->must_eat_times != -1)
		count_eat(philo);
	my_sleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	sleep_and_think(t_philo *philo)
{
	if (philo_print(philo, "is sleeping"))
		return (1);
	my_sleep(philo->info->time_to_sleep);
	if (philo_print(philo, "is thinking"))
		return (1);
	return (0);
}

void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->index % 2)
		usleep(5000);
	while (1)
	{
		if (pickup(philo))
			break ;
		if (eat(philo))
			break ;
		if (sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
