#include "philosophers.h"

int	init_data(t_data *data, char **argv, int argc)
{
	data->num_philo = ft_atoi_basic(argv[1]);
	data->time_to_die = ft_atoi_basic(argv[2]);
	data->time_to_eat = ft_atoi_basic(argv[3]);
	data->time_to_sleep = ft_atoi_basic(argv[4]);
	if (argc == 5)
		data->number_of_eats = ft_atoi_basic(argv[5]);
	else
		data->number_of_eats = -1;
	if (data->num_philo < 2 || data->time_to_die < 0 || data->time_to_eat < 0
			|| data->time_to_sleep < 0)
			return (1);
	data->all_eaten = 0;
	data->dead = 0;
	pthrad_mutex_init(&data->write, NULL);
	pthrad_mutex_init(&data->lock, NULL);
	return (0);
}

int	init_forks(t_data *data)
{
	
}

void	init_philo(pthread_t thread, t_data *data, int id)
{
	t_philo *philo;

	philo->data = data;
	philo->id = id;
	philo->number_of_eats_philo = 0;
	philo->thread = thread;
	philo->time_last_eat = 0;


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

/*int	init_threads(t_data *data)
{
	int			i;
	pthread_t	thread[data->num_philo];

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&thread[i], NULL, thread_routine, (void *)&i) != 0)
			return (1);
		init_philo(thread[i], data, i);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return (1);
}*/

int	init_all(t_data *data, char **argv, int argc)
{
	int	comp;

	if (init_data(data, argv, argc))
		return (1);
	if (init_threads(data))
		return (1);
	if (alloc_data(data))
		return (1);
	if (init_forks(data))
		return (1);
}
