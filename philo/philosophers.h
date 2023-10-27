/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:28:47 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/27 12:56:46 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define FORK 5

struct	s_philo;

typedef struct s_data
{
	pthread_t		*t_id;
	struct s_philo	*philos;
	int				num_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				number_of_eats;
	int				dead;
	int				all_eaten;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}				t_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		thread;
	int				id;
	uint64_t		time_to_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	lock;
	int				number_of_eats;
	int				action;
}				t_philo;

//check_arguments
int			print_param(void);
int			check_args(char *argv[], int argc);

//utils.c
int			is_a_num(char *s);
int			ft_atoi_basic(const char *str);
uint64_t	get_time(void);
char		*str_state(int action);

//init.c
int			init_all(t_data *data, char **argv, int argc);

//errors.c
int			destroy_all(t_data *data);

//thread.c
int			init_threads(t_data *data);
void		*th_routine(void *p);

//state_change.c
void		print_message(int action, t_philo *philo);
void		thread_eat_and_sleep(t_philo *philo);

#endif
