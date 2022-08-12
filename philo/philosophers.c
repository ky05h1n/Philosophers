/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/12 12:07:05 by ky05h1n          ###   ########.fr       */
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
	n = 0;
	if (ac == 5)
	{
		if (input_argcheck(ac, av) == 0)
			return (0);
		else
		{
			while (av[n])
			{
				ptr->num_philo = input_num(av[n]);
				ptr->time_to_die = input_num(av[n + 1]);
			}
		}
	}
	else
		printf("input error\n");
}
