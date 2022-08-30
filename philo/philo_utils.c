/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:27:28 by enja              #+#    #+#             */
/*   Updated: 2022/08/30 02:17:36 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(60);
}

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
	printf("\n NAME\n      - philo\n\n [USAGE]\n\n	~>  ");
	printf("./philo [NUMBER_OF_PHILOSPHERS]");
	printf(" [TIME_TO_DIE] [TIME_TO_EAT]");
	printf("[TIME_TO_SLEEP] [TIME_EACH_PHILOSOPHER_MUST_EAT]");
	printf("\n\n 	    -> The Last Argument is Optional !\n\n\n");
}

void	taken_fork(t_data2 *philo)
{
	pthread_mutex_lock(&philo->ptr_data->forks[philo->l_fork]);
	printf("%ld ms %d has taken a fork %d\n", get_time() - philo->time, philo->philo_id, philo->l_fork);
	pthread_mutex_lock(&philo->ptr_data->forks[philo->r_fork]);
	printf("%ld ms %d has taken a fork %d\n", get_time() - philo->time, philo->philo_id, philo->r_fork);
}

void	is_eating(t_data2 *philo)
{
	printf("%ld ms %d is eating\n", get_time() - philo->time, philo->philo_id);
	ft_usleep(philo->ptr_data->time_to_eat);
}

void	is_sleeping(t_data2 *philo)
{
	pthread_mutex_unlock(&philo->ptr_data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->ptr_data->forks[philo->r_fork]);
	printf("%ld ms %d is sleeping\n", get_time() - philo->time, philo->philo_id);
	ft_usleep(philo->ptr_data->time_to_sleep);
	printf("%ld ms %d is thinking\n", get_time() - philo->time, philo->philo_id);
}