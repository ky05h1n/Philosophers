/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arg_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:46:21 by enja              #+#    #+#             */
/*   Updated: 2022/08/29 23:13:07 by enja             ###   ########.fr       */
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

void	*thread_routing(void *arg)
{
	t_data2				*ptr;

	ptr = (t_data2 *)arg;
	while (1)
	{
		pthread_mutex_lock(&ptr->ptr_data->forks[ptr->l_fork]);
		pthread_mutex_lock(ptr->ptr_data->printing);
		printf("%ld ms %d has taken a fork %d fork\n", get_time() - ptr->time, ptr->philo, ptr->l_fork);
		pthread_mutex_unlock(ptr->ptr_data->printing);
		pthread_mutex_lock(&ptr->ptr_data->forks[ptr->r_fork]);
		pthread_mutex_lock(ptr->ptr_data->printing);
		printf("%ld ms %d has taken a fork %d fork\n", get_time() - ptr->time, ptr->philo, ptr->r_fork);
		pthread_mutex_unlock(ptr->ptr_data->printing);
		pthread_mutex_lock(ptr->ptr_data->printing);
		printf("%ld ms %d is eating\n",get_time() - ptr->time, ptr->philo);
		ptr->last_meal = get_time() - ptr->time;
		pthread_mutex_unlock(ptr->ptr_data->printing);
		ft_usleep(ptr->ptr_data->time_to_eat);
		pthread_mutex_unlock(&ptr->ptr_data->forks[ptr->l_fork]);
		pthread_mutex_unlock(&ptr->ptr_data->forks[ptr->r_fork]);
		pthread_mutex_lock(ptr->ptr_data->printing);
		printf("%ld ms %d is sleeping\n",get_time() - ptr->time, ptr->philo);
		pthread_mutex_unlock(ptr->ptr_data->printing);
		ft_usleep(ptr->ptr_data->time_to_sleep);
		pthread_mutex_lock(ptr->ptr_data->printing);
		printf("%ld ms %d is thinking\n", get_time() - ptr->time, ptr->philo);
		pthread_mutex_unlock(ptr->ptr_data->printing);
	}
	return (NULL);
}

// int timediff(t_data2 ptr)
// {
// 	printf("-----> %ld\n", (get_time() - ptr.last_meal) - ptr.ptr_data->time_start);
// 	return(((get_time() - ptr.last_meal) - ptr.ptr_data->time_start));
// }
void	threads_start(t_data *ptr)
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
		ptr->philos[i].ptr_data = ptr;
		ptr->philos[i].philo = i + 1;
		ptr->philos[i].l_fork = i;
		ptr->philos[i].r_fork = (i + 1) % ptr->num_philo;
	}
	i = -1;
	while (++i < ptr->num_philo)
	{
		pthread_create(&ptr->philos[i].thread, NULL, thread_routing, &ptr->philos[i]);
		usleep(60);
		// ptr->philos[i].last_meal = get_time() - ptr->philos[i].time;
		// printf("-->> me\n");
	}
	i = 0;
	while (1)
	{
			// printf("----> %ld\n", get_time() - ptr->time_start);
		if ((get_time() - ptr->time_start) - (ptr->philos[i].last_meal) >= ptr->time_to_die)
		{
			pthread_mutex_lock(ptr->philos[i].ptr_data->printing);
			printf("%ld ms %d died\n", get_time() - ptr->philos[i].time, ptr->philos[i].philo);
			pthread_mutex_lock(ptr->philos[i].ptr_data->printing);
			break;
		}
		i++;
		if (ptr->num_philo == i)
			i = 0;
	}
}
