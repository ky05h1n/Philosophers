/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threadinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:35:23 by enja              #+#    #+#             */
/*   Updated: 2022/08/30 02:16:23 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	struct_creat(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->num_philo)
		pthread_mutex_init(&ptr->forks[i], NULL);
	i = -1;
	while (++i < ptr->num_philo)
	{
		ptr->philos[i].time = get_time();
		ptr->philos[i].ptr_data = ptr;
		ptr->philos[i].philo_id = i + 1;
		ptr->philos[i].l_fork = i;
		ptr->philos[i].r_fork = (i + 1) % ptr->num_philo;
	}
	threads_creat(ptr);
}

void	threads_creat(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->num_philo)
	{
		pthread_create(&ptr->philos[i].thread, NULL, thread_start,
			&ptr->philos[i]);
		usleep(60);
	}
	while (1);
}

void	*thread_start(void *arg)
{
	t_data2	*ptr;

	ptr = (t_data2 *)arg;
	while (1)
	{
		taken_fork(ptr);
		is_eating(ptr);
		is_sleeping(ptr);
	}
}