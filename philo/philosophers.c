/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/25 00:21:38 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_time(void)
{
	struct timeval	timing;
	long int		time;

	if (gettimeofday(&timing, NULL) == -1)
		return (0);
	time = (timing.tv_sec * 1000) + (timing.tv_usec / 1000);
	return (time);
}

void	ft_usleep(int time)
{
	while (time > 100)
	{
		usleep(100);
		time -= 100;
	}
	usleep(time);
}

int	input_num(char *av)
{
	int	i;
	int	some;

	some = 0;
	i = 0;
	while (av[i])
	{
		some = some * 10 + (av[i] - '0');
		i++;
	}
	return (some);
}

int	input_argcheck(int ac, char **av)
{
	int	idx;
	int	ndx;

	idx = 1;
	ndx = 0;
	while (idx < ac)
	{
		if (av[idx][0] == '0')
			return (0);
		while (av[idx][ndx])
		{
			if (av[idx][ndx] >= '0' && av[idx][ndx] <= '9')
				ndx++;
			else
				return (0);
		}
		idx++;
		ndx = 0;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*ptr;

	ptr = malloc(sizeof(t_data));
	(void)av;
	if (ac == 5 || ac == 6)
	{
		ptr = arg_treatemnt(ac, av, ptr);
		if (!ptr)
			return (0);
		if (ac == 5)
		{
			ptr->philos = malloc(ptr->num_philo * sizeof(t_data2));
			ptr->forks = malloc(ptr->num_philo * sizeof(pthread_mutex_t));
			threads_start(ptr);
			// printf("num_philo = %d\ntime_to_die = %d\ntime_to_eat = %d\ntime_to_sleep = %d\n", ptr->num_philo, ptr->time_to_die, ptr->time_to_eat, ptr->time_to_sleep);
		}
		else if (ac == 6)
		{
			// printf("num_philo = %d\ntime_to_die = %d\ntime_to_eat = %d\ntime_to_sleep = %d\ntime_each_must_eat = %d\n", ptr->num_philo, ptr->time_to_die, ptr->time_to_eat, ptr->time_to_sleep, ptr->time_each_must_eat);
			
		}
	}
	else
		printf("\n NAME\n      - philo\n\n [USAGE]\n\n	~>  ./philo [NUMBER_OF_PHILOSPHERS] [TIME_TO_DIE] [TIME_TO_EAT] [TIME_TO_SLEEP] [TIME_EACH_PHILOSOPHER_MUST_EAT]\n\n 	    -> The Last Argument is Optional !\n\n\n");
	return (0);
}