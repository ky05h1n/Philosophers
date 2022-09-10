#! /bin/sh

while : true
do
	./philo 5 800 200 200 7 | grep "is eating" | wc -l
done


