/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/15 18:16:11 by enja             ###   ########.fr       */
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

void	assing_data(t_data *ptr, char **av)
{
	ptr->num_philo = input_num(av[1]);
	ptr->time_to_die = input_num(av[2]);
	ptr->time_to_eat = input_num(av[3]);
	ptr->time_to_sleep = input_num(av[4]);
}

int	main(int ac, char **av)
{
	t_data	*ptr;

	(void)av;
	if (ac == 5)
	{
		ptr = arg_treatemnt(ac, av);
		if (!ptr)
			return (0);
		printf("num_philo = %d\ntime_to_die = %d\ntime_to_eat = %d\ntime_to_sleep = %d\n", ptr->num_philo, ptr->time_to_die, ptr->time_to_eat, ptr->time_to_sleep);
	}
	return (0);
}