/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threadinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:35:23 by enja              #+#    #+#             */
/*   Updated: 2022/09/10 00:57:50 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	struct_creat(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->num_philo)
		pthread_mutex_init(&ptr->forks[i], NULL);
	pthread_mutex_init(&ptr->edit, NULL);
	pthread_mutex_init(&ptr->lock, NULL);
	pthread_mutex_init(&ptr->sin, NULL);
	pthread_mutex_init(&ptr->print, NULL);
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
	ptr->sig = 0;
	while (++i < ptr->num_philo)
	{
		pthread_create(&ptr->philos[i].thread, NULL, thread_start,
			&ptr->philos[i]);
	}
	i = 0;
	while (1)
	{
		if (i == ptr->num_philo)
			i = 0;
		pthread_mutex_lock(&ptr->sin);
		if (ptr->sig == 1)
			return (NULL);
		pthread_mutex_unlock(&ptr->sin);
		pthread_mutex_lock(&ptr->lock);
		if ((get_time() - ptr->philos[i].time) - ptr->philos[i].last_meal
			>= ptr->time_to_die)
		{
			pthread_mutex_lock(&ptr->edit);
			printf("%ld ms %d died", get_time() - ptr->philos[i].time,
				ptr->philos[i].philo_id);
			return (NULL);
			pthread_mutex_unlock(&ptr->edit);
		}
		pthread_mutex_unlock(&ptr->lock);
		i++;
	}
	return (NULL);
}

void	*thread_start(void *arg)
{
	t_data2	*ptr;
	
	ptr = (t_data2 *)arg;
	if (ptr->philo_id % 2 == 0)
		usleep(200);
	while (1)
	{
		taken_fork(ptr);
		is_eating(ptr);
		is_sleeping(ptr);
	}
}
