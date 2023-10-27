/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:55:08 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/27 14:27:52 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->all_eaten >= philo->data->num_philo)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

//supervisor d'un fil
void	*th_supervisor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (philo->data->dead == 0)
	{
		printf("Data dead a fora = %d\n", philo->data->dead);
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->action != EATING)
			print_message(DEAD, philo);
		if (philo->number_of_eats == philo->data->number_of_eats)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->all_eaten++;
			philo->number_of_eats++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*th_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->time_to_die = philo->data->time_to_die + get_time();
	if (pthread_create(&philo->thread, NULL, &th_supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		thread_eat_and_sleep(philo);
		print_message(THINKING, philo);
	}
	if (pthread_join(philo->thread, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	init_threads(t_data *data)
{
	int			i;
	pthread_t	thread;

	i = 0;
	data->start_time = get_time();
	if (data->number_of_eats > 0)
	{
		if (pthread_create(&thread, NULL, &monitor, &data->philos[0]))
			return (destroy_all(data));
	}
	while (i < data->num_philo)
	{
		if (pthread_create(&data->t_id[i], NULL, &th_routine, &data->philos[i]))
			return (destroy_all(data));
		i++;
		usleep(1);
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->t_id[i], NULL))
			return (destroy_all(data));
		i++;
	}
	return (0);
}
