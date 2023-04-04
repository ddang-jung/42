/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:15:56 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/03/29 20:55:14 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		init[i].index = i + 1;
		init[i].status = NORM;
		init[i].count_eat = 0;
		init[i].last_eat = 0;
		init[i].l_fork = &info->fork[i];
		if (i == 0)
			init[i].r_fork = &info->fork[info->num_philo - 1];
		else
			init[i].r_fork = &info->fork[i - 1];
		pthread_mutex_init(&init[i].m_status, 0);
		pthread_mutex_init(&init[i].m_last_eat, 0);
		init[i].info = info;
	}
	return (init);
}

int	check_valid(t_info *info, int ac)
{
	if (info->num_philo < 1 || \
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
	return (0);
}

int	init(t_info *info, int ac, char **av)
{
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat_times = ft_atoi(av[5]);
	else
		info->must_eat_times = -1;
	info->status = NORM;
	info->start_time = 0;
	pthread_mutex_init(&info->print, 0);
	pthread_mutex_init(&info->m_status, 0);
	info->fork = init_fork(info->num_philo);
	info->philo = init_philo(info);
	return (check_valid(info, ac));
}
