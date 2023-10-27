/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:28:25 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/27 12:28:15 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->t_id[0], NULL, &th_routine, &data->philos[0]))
		return (destroy_all(data));
	pthread_detach(data->t_id[0]);
	while (!data->dead)
		usleep(0);
	destroy_all(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
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
