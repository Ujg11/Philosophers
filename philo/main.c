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

int	case_one(t_data *data)
{
	
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
		return (case_one(&data));
	if (thread_init(&data))
		return (1);
	destroy_all(&data);
	return (0);
}
