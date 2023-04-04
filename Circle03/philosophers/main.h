/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:27:13 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/03/29 22:26:22 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR -1
# define SUCCESS 0

typedef enum e_status
{
	NORM,
	FULL,
	DEAD,
}	t_status;

typedef struct s_philo
{
	int				index;
	int				status;
	int				count_eat;
	long long		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	m_status;
	pthread_mutex_t	m_last_eat;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				status;
	long long		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	m_status;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}	t_info;

// UTILS
int			error_handler(char *msg);
static int	ft_isspace(char c);
int			ft_atoi(const char *str);
long long	get_time(void);

// INIT
int			init(t_info *info, int ac, char **av);

#endif