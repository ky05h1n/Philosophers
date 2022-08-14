/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arg_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:46:21 by enja              #+#    #+#             */
/*   Updated: 2022/08/14 22:02:39 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*arg_treatemnt(int ac, char **av)
{
	t_data	ph_data;
	t_data	*ptr;

	ptr = &ph_data;
	if (input_argcheck(ac, av) == 0)
	{
		printf("input error\n");
		return (NULL);
	}
	else
		assing_data(ptr, av);
	return (ptr);
}
