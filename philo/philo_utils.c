/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:27:28 by enja              #+#    #+#             */
/*   Updated: 2023/04/10 21:13:28 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



long int	get_time(void)
{
	struct timeval	timing;
	long int		time;

	if (gettimeofday(&timing, NULL) == -1)
		return (0);
	time = (timing.tv_sec * 1000) + (timing.tv_usec / 1000);
	return (time);
}

void	msg(void)
{
	printf("\n [ NAME ]\n\n      - philo\n\n [ USAGE ]\n\n	~>  ");
	printf("./philo [NUMBER_OF_PHILOSPHERS]");
	printf(" [TIME_TO_DIE] [TIME_TO_EAT]");
	printf("[TIME_TO_SLEEP] [TIME_EACH_PHILOSOPHER_MUST_EAT]");
	printf("\n\n 	    -> The Last Argument is Optional !");
	printf("\n\n 	    -> The Arguments Must Be Numbers Only !\n\n\n");
}

void	taken_fork(t_data2 *philo)
{
	pthread_mutex_lock(&philo->ptr_data->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->ptr_data->edit);
	printf("%ld ms %d has taken a fork %d\n", get_time()
		- philo->time, philo->philo_id, philo->l_fork);
	pthread_mutex_unlock(&philo->ptr_data->edit);
	pthread_mutex_lock(&philo->ptr_data->forks[philo->r_fork]);
	pthread_mutex_lock(&philo->ptr_data->edit);
	printf("%ld ms %d has taken a fork %d\n", get_time()
		- philo->time, philo->philo_id, philo->r_fork);
	pthread_mutex_unlock(&philo->ptr_data->edit);
}

void	is_eating(t_data2 *philo)
{
	pthread_mutex_lock(&philo->ptr_data->edit);
	printf("%ld ms %d is eating\n", get_time() - philo->time, philo->philo_id);
	pthread_mutex_unlock(&philo->ptr_data->edit);
	pthread_mutex_lock(&philo->ptr_data->sin);
	philo->ptr_data->num_eat++;
	if (philo->ptr_data->time_each_must_eat > 0 && philo->ptr_data->num_philo
		* philo->ptr_data->time_each_must_eat == philo->ptr_data->num_eat)
		philo->ptr_data->sig = 1;
	pthread_mutex_unlock(&philo->ptr_data->sin);
	pthread_mutex_lock(&philo->ptr_data->lock);
	philo->last_meal = get_time() - philo->time;
	pthread_mutex_unlock(&philo->ptr_data->lock);
	ft_usleep(philo->ptr_data->time_to_eat);
}

void	is_sleeping(t_data2 *philo)
{
	pthread_mutex_unlock(&philo->ptr_data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->ptr_data->forks[philo->r_fork]);
	pthread_mutex_lock(&philo->ptr_data->edit);
	printf("%ld ms %d is sleeping\n", get_time() - philo->time, philo->philo_id);
	pthread_mutex_unlock(&philo->ptr_data->edit);
	ft_usleep(philo->ptr_data->time_to_sleep);
	pthread_mutex_lock(&philo->ptr_data->edit);
	printf("%ld ms %d is thinking\n", get_time() - philo->time, philo->philo_id);
	pthread_mutex_unlock(&philo->ptr_data->edit);
}