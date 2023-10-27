/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:37 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/27 11:43:21 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_param(void)
{
	printf("Format dels parametres: \nnumber_of_philosophers time_to_die ");
	printf("time_to_eat time_to_sleep");
	printf(" number_of_times_each_philosopher_must_eat(opcional)\n");
	return (1);
}

int	check_args(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_a_num(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
