/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:47 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/25 11:32:43 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		while (i < data->num_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philos[i].lock);
			i++;
		}
		pthread_mutex_destroy(&data->write);
		pthread_mutex_destroy(&data->lock);
		if (data->t_id)
			free(data->t_id);
		if (data->forks)
			free(data->forks);
		if (data->philos)
			free(data->philos);
	}
	return (1);
}
