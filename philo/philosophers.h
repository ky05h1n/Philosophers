/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:15:08 by enja              #+#    #+#             */
/*   Updated: 2022/09/10 01:46:12 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct t_data{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_each_must_eat;
	int				num_eat;
	long int		time_start;
	int				sig;
	pthread_mutex_t	sin;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	edit;
	pthread_mutex_t	lock;
	struct t_data2	*philos;
}t_data;

typedef struct t_data2{
	pthread_t		thread;
	int				philo_id;
	int				l_fork;
	int				r_fork;
	long int		time;
	long int		last_meal;
	t_data			*ptr_data;
}t_data2;

t_data		*arg_treatemnt(int ac, char **av, t_data *ptr);
int			input_argcheck(int ac, char **av);
void		assing_data(t_data *ptr, char **av, int sing);
int			input_num(char *av);
void		struct_creat(t_data *ptr);
void		*threads_creat(t_data *ptr);
void		*thread_start(void *arg);
void		thread_check(t_data *ptr);
long int	get_time(void);
void		ft_usleep(int time);
void		msg(void);
void		taken_fork(t_data2 *philo);
void		is_eating(t_data2 *philo);
void		is_sleeping(t_data2 *philo);

#endif