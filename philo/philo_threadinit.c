/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threadinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:35:23 by enja              #+#    #+#             */
/*   Updated: 2022/09/05 16:06:36 by enja             ###   ########.fr       */
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
		ptr->philos[i].last_meal = 0;
		ptr->num_eat = 0;
		ptr->philos[i].ptr_data = ptr;
		ptr->philos[i].philo_id = i + 1;
		ptr->philos[i].l_fork = i;
		ptr->philos[i].r_fork = (i + 1) % ptr->num_philo;
	}
	threads_creat(ptr);
}

void	*threads_creat(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->num_philo)
	{
		pthread_create(&ptr->philos[i].thread, NULL, thread_start,
			&ptr->philos[i]);
		usleep(200);
	}
	i = 0;
	while (1)
	{
		if (i == ptr->num_philo)
			i = 0;
		if ((get_time() - ptr->philos[i].time) - ptr->philos[i].last_meal >= ptr->time_to_die)
		{
			printf("%ld ms %d died", get_time() - ptr->philos[i].time, ptr->philos[i].philo_id);
			return (NULL);
		}
		if (ptr->time_each_must_eat > 0 && ptr->num_philo * ptr->time_each_must_eat == ptr->num_eat)
			return (NULL);
		i++;
	}
	return (NULL);
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
