#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR -1
# define OK 0

typedef enum e_status
{
	NORM,
	FULL,
	DEAD,
}	t_status;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_i;
	int				philo_status;
	int				philo_eat_count;
	long long		philo_last_eat_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	m_philo_last_eat_time;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				full;
	int				status;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_full;
	pthread_mutex_t	m_status;
	pthread_mutex_t	m_print;
	t_philo			*philo;
}	t_info;

// CHECK
int			check(int ac, char **av);

// INIT
int			init(t_info *info, int ac, char **av);

// RUN
int			run(t_info *info);

// PHILO
void		routine(void *philo_void);
void		philo_print(t_philo *philo, char *msg);


// CLEAN
int			clean(t_info *info);

// UTILS
int			ft_isspace(char c);
int			ft_atoi(const char *str);
long long	get_time(void);
void		my_sleep(int time);

#endif