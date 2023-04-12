/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:36:33 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/04/11 20:22:52 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define OK 0

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	int				count;
	long long		last_eat;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_full;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				is_end;
	int				full_philo;
	long long		start_time;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_full;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}	t_info;

// INIT
int			init(t_info *info, int ac, char **av);

// RUN
int			run(t_info *info);
int			philo_print(t_philo *philo, char *msg);

// ROUTINE
void		*routine(void *philo_void);

// UTILS
int			error(char *msg);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
long long	get_time(void);
void		my_sleep(int time);

#endif