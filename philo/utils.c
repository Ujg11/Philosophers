/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:28:57 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/25 13:55:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_a_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_basic(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

//devuelve el tiempo en milisegundos
uint64_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return ((uint64_t)(t.tv_sec * 1000 + t.tv_usec / 1000));
}

char	*str_state(int action)
{
	if (action == EATING)
		return ("is eating");
	else if (action == SLEEPING)
		return ("is sleeping");
	else if (action == THINKING)
		return ("is thinking");
	else if (action == DEAD)
		return ("died");
	else if (action == FORK)
		return ("has taken a fork");
}
