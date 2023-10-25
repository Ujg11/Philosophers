/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:28:25 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/25 15:54:16 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_one(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->time_to_die = philo->data->time_to_die + get_time();
	print_message(FORK, philo);
	while (philo->time_to_die > get_time())
		philo->action = EATING;
	print_message(DEAD, philo);
	return ((void *)1);
}

int	one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->t_id[0], NULL, &routine_one, &data->philos[0]))
		return (destroy_all(data));
	if (pthread_join(data->t_id[0], NULL))
			return (destroy_all(data));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 4 || argc > 5)
		return (print_param());
	if (check_args(argv, argc))
		return (print_param());
	if (init_all(&data, argv, argc))
		return (1);
	if (data.num_philo == 1)
		return (one_philo(&data));
	if (init_threads(&data))
		return (1);
	destroy_all(&data);
	return (0);
}
