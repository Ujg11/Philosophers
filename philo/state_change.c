#include "philosophers.h"

void	print_message(int action, t_philo *philo)
{
	uint64_t	t;

	pthread_mutex_lock(&philo->data->write);
	t = get_time() - philo->data->start_time;
	printf("%llu %d %s", t, philo->id, str_state(action));
	pthread_mutex_unlock(&philo->data->write);
}

void	thread_eat_and_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(philo->left_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(&philo->lock);
	philo->action == EATING;
	print_message(EATING, philo);
	usleep(philo->data->time_to_eat);
	philo->number_of_eats++;
	philo->action == SLEEPING;
	philo->time_to_die = get_time() + philo->data->time_to_die;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_message(SLEEPING, philo);
	usleep(philo->data->time_to_sleep);
	philo->action = THINKING;
	pthread_mutex_unlock(&philo->lock);
}
