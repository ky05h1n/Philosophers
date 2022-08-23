/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:15:08 by enja              #+#    #+#             */
/*   Updated: 2022/08/23 18:38:43 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct t_data{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_each_must_eat;
	pthread_mutex_t	*forks;
	struct t_data2	*philos;
}t_data;

typedef struct t_data2{
	pthread_t		thread;
	int				philo;
	int				l_fork;
	int				r_fork;
	t_data			*ptr_data;
}t_data2;

t_data	*arg_treatemnt(int ac, char **av, t_data *ptr);
int		input_argcheck(int ac, char **av);
void	assing_data(t_data *ptr, char **av, int sing);
int		input_num(char *av);
void	threads_start(t_data *ptr);
void	init_mutex(void);
void	*synch_thread(void *ptr);
void	is_eating(int i, t_data2 ptr);
void	is_sleeping(int i, t_data2 ptr);

#endif