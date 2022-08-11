/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/11 18:58:48 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	(void)av;
	if (ac == 5)
	{
		if (input_argcheck(ac, av) == 0)
			return (0);
		else
			printf("its good");
	}
	else
		printf("input error\n");
}
