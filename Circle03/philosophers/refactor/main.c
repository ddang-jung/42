/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:25:51 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/04/04 13:03:38 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	mysleep(int time)
{
	long long	target;

	target = get_time() + (long long)time;
	while (target > get_time())
		usleep(50);
}

void	philo_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print);
	printf("%lld\t", get_time() - philo->info->start_time);
	printf("%d %s\n", philo->index, msg);
	pthread_mutex_unlock(&philo->info->print);
}

int	check_arguments(int ac, char **av)
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
	return (0);
}

void	check_philo_status(t_info *info)
{
	long long	current;
	int			i;

	while (1)
	{
		i = -1;
		while (++i < info->num_philo)
		{
			current = get_time();
			if (current - info->philo[i].last_eat >= \
				(long long)info->time_to_die)
				return (philo_dead(info));
		}
	}
}

void	philo_routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->index % 2)
		mysleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->info->m_status);
		if (philo->info->status == DEAD)
		{
			pthread_mutex_unlock(&philo->info->m_status);
			return ;
		}
		pthread_mutex_lock(philo->l_fork);
		philo_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		philo_print(philo, "has taken a fork");
		philo_print(philo, "is eating");
		mysleep(philo->info->time_to_eat);
		pthread_mutex_lock(&philo->m_last_eat);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->m_last_eat);
		philo->count_eat++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo_print(philo, "is sleeping");
		mysleep(philo->info->time_to_sleep);
		philo_print(philo, "is thinking");
	}
}

int	main_loop(t_info *info)
{
	t_philo		*philo;
	int			i;
	long long	time;

	info->start_time = get_time();
	i = -1;
	while (++i < info->num_philo)
	{
		philo = &info->philo[i];
		philo->last_eat = get_time();
		if (pthread_create(&philo->thread, NULL, (void *)philo_routine, philo))
			return (ERROR);
	}
	while (1)
	{
		i = -1;
		while (++i < info->num_philo)
		{
			philo = &info->philo[i];
			pthread_mutex_lock(&philo->m_last_eat);
			if (get_time() - philo->last_eat >= info->time_to_die)
			{
				philo->status = DEAD;
				info->status = DEAD;
				pthread_mutex_unlock(&philo->m_last_eat);
				philo_print(philo, "died");
				return (0);
			}
			pthread_mutex_unlock(&philo->m_last_eat);
		}
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (check_arguments(ac, av) == ERROR)
		return (error_handler("Unvalid Arguments."));
	if (init(&info, ac, av) == ERROR)
		return (error_handler("init() Error."));
	if (main_loop(&info) == ERROR)
		return (error_handler("main_loop() Error."));
	return (0);
}
