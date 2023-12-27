/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:39:52 by ojimenez          #+#    #+#             */
/*   Updated: 2023/12/27 15:11:52 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(int action, t_philo *philo)
{
	uint64_t	t;

	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_lock(&philo->data->lock);
	t = get_time() - philo->data->start_time;
	if (action == DEAD && philo->data->dead == 0)
	{
		printf("%llu %d %s\n", t, philo->id, str_state(action));
		philo->data->dead = 1;
	}
	if (philo->data->dead == 0)
		printf("%llu %d %s\n", t, philo->id, str_state(action));
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(philo->left_fork);
	print_message(FORK, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_message(SLEEPING, philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	thread_eat_and_sleep(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->action = EATING;
	philo->time_to_die = get_time() + philo->data->time_to_die;
	print_message(EATING, philo);
	philo->number_of_eats++;
	ft_usleep(philo->data->time_to_eat);
	philo->action = SLEEPING;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
	philo->action = THINKING;
}
