#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	pthread_t		*t_id;
	t_philo			*philos;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eats;
	int				dead;
	int				all_eaten;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	
}				t_data;

typedef struct s_philo
{
	struct t_data	*data;
	pthread_t		thread;
	int				id;
	int				time_last_eat;
	unsigned int	time_to_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock;
	int				number_of_eats_philo;
}				t_philo;


//check_arguments
int	print_param(void);
int	check_args(char *argv[], int argc);

//utils.c
int	is_a_num(char *s);
int	ft_atoi_basic(const char *str);

//init.c
int	init_all(t_data *data, char **argv, int argc);
int	ft_atoi_basic(const char *str);

//errors.c
int	destroy_all(t_data *data);

#endif