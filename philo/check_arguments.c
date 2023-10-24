#include "philosophers.h"

int	print_param(void)
{
	printf("Format dels parametres: \number_of_philosophers time to die time_to_eat");
	printf("time_to_slep number_of_times_each_philosopher_must_eat(opcional)");
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