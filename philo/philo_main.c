/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:03:18 by enja              #+#    #+#             */
/*   Updated: 2022/08/30 02:15:46 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*ptr;

	ptr = malloc(sizeof(t_data));
	ptr->time_start = get_time();
	(void)av;
	if (ac == 5 || ac == 6)
	{
		ptr = arg_treatemnt(ac, av, ptr);
		if (!ptr)
			return (0);
		ptr->philos = malloc(ptr->num_philo * sizeof(t_data2));
		ptr->forks = malloc(ptr->num_philo * sizeof(pthread_mutex_t));
		ptr->printing = malloc(sizeof(pthread_mutex_t));
		struct_creat(ptr);
		return (0);
	}
	else
		msg();
	return (0);
}
