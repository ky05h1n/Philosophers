/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arg_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:46:21 by enja              #+#    #+#             */
/*   Updated: 2022/08/25 00:23:56 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assing_data(t_data *ptr, char **av, int sing)
{
	ptr->num_philo = input_num(av[1]);
	ptr->time_to_die = input_num(av[2]);
	ptr->time_to_eat = input_num(av[3]);
	ptr->time_to_sleep = input_num(av[4]);
	if (sing == 1)
		ptr->time_each_must_eat = input_num(av[5]);
}

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

void	is_eating(t_data2 *ptr)
{
	while (1)
	{
		pthread_mutex_lock(&ptr->ptr_data->forks[ptr->l_fork]);
		printf("philo %d taken left %d fork\n", ptr->philo, ptr->l_fork);
		pthread_mutex_lock(&ptr->ptr_data->forks[ptr->r_fork]);
		printf("philo %d taken right %d fork\n", ptr->philo, ptr->r_fork);
		printf("philo %d is eating\n", ptr->philo);
		sleep(1);
		pthread_mutex_unlock(&ptr->ptr_data->forks[ptr->l_fork]);
		pthread_mutex_unlock(&ptr->ptr_data->forks[ptr->r_fork]);
		usleep(200);
	}
	return ;
}

void	*synch_thread(void *arg)
{
	t_data2				*ptr;

	ptr = (t_data2 *)arg;
	if (ptr->philo % 2 == 1)
		is_eating(ptr);
	else
	{
		usleep(200);
		is_eating(ptr);
	}
	return (NULL);
}

void	threads_start(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->num_philo)
		pthread_mutex_init(&ptr->forks[i], NULL);
	i = -1;
	while (++i < ptr->num_philo)
	{
		ptr->philos[i].ptr_data = ptr;
		ptr->philos[i].philo = i + 1;
		ptr->philos[i].l_fork = i;
		ptr->philos[i].r_fork = (i + 1) % ptr->num_philo;
		pthread_create(&ptr->philos[i].thread, NULL, synch_thread,
			&ptr->philos[i]);
		usleep(110000);
	}
	i = -1;
	while (++i < ptr->num_philo)
		pthread_join(ptr->philos[i].thread, NULL);
}
