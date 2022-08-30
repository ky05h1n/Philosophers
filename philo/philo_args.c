/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:46:21 by enja              #+#    #+#             */
/*   Updated: 2022/08/29 23:36:39 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*arg_treatemnt(int ac, char **av, t_data *ptr)
{
	if (input_argcheck(ac, av) == 0)
	{
		printf("input error\n");
		return (NULL);
	}
	else
	{
		if (ac == 5)
			assing_data(ptr, av, 0);
		else
			assing_data(ptr, av, 1);
	}
	return (ptr);
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

void	assing_data(t_data *ptr, char **av, int sing)
{
	ptr->num_philo = input_num(av[1]);
	ptr->time_to_die = input_num(av[2]);
	ptr->time_to_eat = input_num(av[3]);
	ptr->time_to_sleep = input_num(av[4]);
	if (sing == 1)
		ptr->time_each_must_eat = input_num(av[5]);
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
