/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:53:52 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 16:36:00 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	philo->time_to_death = timestamp() + philo->table->time_die;
	if(philo->index % 2 == 0)
	{
		usleep(10000);
	}

	while(1)
	{
		print_action(philo,"is thinking");
		if(!eat_philo(philo))
			break;
		if(!have_eaten(philo))
			break;
		if(!philo_sleep(philo))
			break;

	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo *watcher;
	t_table	*table;
	int		i;
	long	ms;

	table = arg;
	i = 0;
	ms = timestamp() - table->start_simulation;
	while(1)
	{
		watcher = &table->philos[i];
		if(watcher->death == 1)
		{
			table->end_simulation = 1;
			pthread_mutex_lock(&watcher->table->mutex_print);
			printf("%ld ms ",ms);
			printf("%d died\n", table->philos[i].index);
			pthread_mutex_unlock(&watcher->table->mutex_print);
			break;
		}
		if(watcher->full == 1)
			watcher->philo_stop = 1;
		if(i == table->nbr_philo)
			i = 0;
		i++;
	}
	return (NULL);
}

void	init_philo(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nbr_philo)
    {
		table->philos[i] = (t_philo){0};
		//printf("nbr_fork-> %ld\n",table->philos[i].nbr_fork);
        table->philos[i].index = i + 1;
		table->philos[i].fork = 1;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->nbr_philo;
        table->philos[i].table = table;
		pthread_mutex_init(&table->philos[i].mutex_fork, NULL);
		//printf("philo-> %d\n",table->philos[i].index);
		i++;
    }
	i = 0;
	while(i < table->nbr_philo)
	{
		pthread_create(&table->philos[i].thread_id, NULL, routine, &table->philos[i]);
		i++;
	}
}