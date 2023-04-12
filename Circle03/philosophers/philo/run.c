/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:17:42 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/04/11 20:17:55 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	philo_print(t_philo *philo, char *msg)
{
	long long	timestamp;

	timestamp = get_time() - philo->info->start_time;
	pthread_mutex_lock(philo->m_print);
	if (philo->info->is_end)
	{
		pthread_mutex_unlock(philo->m_print);
		return (1);
	}
	printf("%lld\t %d %s\n", timestamp, philo->index, msg);
	pthread_mutex_unlock(philo->m_print);
	return (0);
}

int	check_dead(t_philo *philo, long long now)
{	
	pthread_mutex_lock(philo->m_eat);
	if (now - philo->last_eat >= philo->info->time_to_die)
	{
		pthread_mutex_lock(philo->m_print);
		printf("%lld\t %d died\n", now - philo->info->start_time, philo->index);
		philo->info->is_end = 1;
		pthread_mutex_unlock(philo->m_print);
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
		printf("%lld\t all philos are full\n", get_time() - info->start_time);
		info->is_end = 1;
		pthread_mutex_unlock(&info->m_print);
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
