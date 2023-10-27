/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:28:10 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/27 11:48:02 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_data(t_data *data, char **argv, int argc)
{
	data->num_philo = ft_atoi_basic(argv[1]);
	data->time_to_die = (uint64_t)ft_atoi_basic(argv[2]);
	data->time_to_eat = (uint64_t)ft_atoi_basic(argv[3]);
	data->time_to_sleep = (uint64_t)ft_atoi_basic(argv[4]);
	if (argc == 6)
		data->number_of_eats = ft_atoi_basic(argv[5]);
	else
		data->number_of_eats = -1;
	if (data->num_philo < 2 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (1);
	data->all_eaten = 0;
	data->dead = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (0);
}

int	alloc_data(t_data *data)
{
	data->t_id = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->t_id)
		return (destroy_all(data));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (destroy_all(data));
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (destroy_all(data));
	return (0);
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	data->philos[0].left_fork = &data->forks[0];
	data->philos[0].right_fork = &data->forks[data->num_philo - 1];
	i = 1;
	while (i < data->num_philo)
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].action = THINKING;
		data->philos[i].number_of_eats = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	init_all(t_data *data, char **argv, int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (alloc_data(data))
		return (1);
	init_forks(data);
	init_philos(data);
	return (0);
}
