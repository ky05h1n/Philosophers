/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:04:36 by enja              #+#    #+#             */
/*   Updated: 2022/08/14 22:04:03 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct t_data{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}t_data;

t_data	*arg_treatemnt(int ac, char **av);
int		input_argcheck(int ac, char **av);
void	assing_data(t_data *ptr, char **av);
#endif
