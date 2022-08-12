/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/12 17:26:52 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	t_data	ph_data;
	t_data	*ptr;
	int		n;

	ptr = &ph_data;
	(void)av;
	n = 1;
	if (ac == 5)
	{
		if (input_argcheck(ac, av) == 0)
		{
			printf("input error\n");
			return (0);
		}
		else
		{
			ptr->num_philo = input_num(av[n++]);
			ptr->time_to_die = input_num(av[n++]);
			ptr->time_to_eat = input_num(av[n++]);
			ptr->time_to_sleep = input_num(av[n++]);
		}
		printf("num_philo = %d\ntime_to_die = %d\ntime_to_eat = %d\ntime_to_sleep = %d", ptr->num_philo, ptr->time_to_die, ptr->time_to_eat, ptr->time_to_sleep);
	}

	else
		printf("input error\n");
}
