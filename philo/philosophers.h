/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:04:36 by enja              #+#    #+#             */
/*   Updated: 2022/08/12 12:03:12 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct t_data{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}t_data;

#endif
