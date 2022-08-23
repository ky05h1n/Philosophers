/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:46:20 by enja              #+#    #+#             */
/*   Updated: 2022/08/20 20:21:23 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long int tmp = 0;
pthread_mutex_t lock;

void	func_one(void *arg)
{
	int i = 1;
	while (i < 500000)
	{
		// printf("my turn %d\n", tmp);
		pthread_mutex_lock(&lock);
		tmp = tmp + i;
		i++;
		pthread_mutex_unlock(&lock);
	}
}

void	func_two(void *arg)
{
	int i = 500000;
	while (i <= 1000000)
	{
		pthread_mutex_lock(&lock);
		tmp = tmp + i;
		i++;
		pthread_mutex_unlock(&lock);
	}
}

int	main(void)
{
	pthread_t	pt1, pt2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&pt1, NULL, (void *)&func_one, NULL);
	pthread_create(&pt2, NULL,(void *)&func_two, NULL);
	pthread_join(pt1, NULL);
	pthread_join(pt2, NULL);
	pthread_mutex_destroy(&lock);
	printf("%ld\n", tmp);
}