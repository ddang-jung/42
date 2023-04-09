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

typedef enum e_status
{
	NORM,
	FULL,
	DEAD,
}	t_status;

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

// PHILO
void		pickup(t_philo *philo);
void		eat(t_philo *philo);
void		sleep_and_think(t_philo *philo);

// UTILS
int			error(char *msg);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
long long	get_time(void);
void		my_sleep(int time);

#endif