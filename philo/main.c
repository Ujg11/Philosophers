#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 4 || argc > 5)
		return (print_param());
	if (check_args(argv, argc))
		return (print_param());
	if (init_all(&data, argv, argc))
		return (1);
	
}