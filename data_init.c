/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:13:16 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/16 16:58:57 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// criar routine
//void	*
//criar monitor
//criar função de comer
//devolver o garfo depois de comer
//checar se eles comeram
//fazer a função de dormir

void	*routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	philo->time_to_death = timestamp() + philo->table->time_die;
	if(philo->index % 2 == 0)
		usleep(100);
	while(1)
	{
		print_action(philo,"pensando de cria");
		if(!eat(philo))
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

	table = arg;
	i = 0;
	while(1)
	{
		watcher = &table->philos[i];
		if(watcher->death == 1)
		{
			table->end_simulation = 1;
			pthread_mutex_lock(&watcher->table->mutex_print);
			printf("philosopher[%ld] died\n", table->philos[i].index);
			pthread_mutex_unlock(&watcher->table->mutex_print);
			break;
		}
		if(watcher->full == 1)
			watcher->stop = 1;
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
        table->philos[i].index = i + 1;
        table->philos[i].fork = i + 1;
        table->philos[i].mutex_fork = table->philos[i].mutex_fork;
        table->philos[i].table = table;
		pthread_mutex_init(&table->philos[i].mutex_fork, NULL);
        pthread_create(&table->philos[i].thread_id, NULL, routine, &table->philos[i]);
		i++;
    }
}

void	data_init(t_table *table, char **argv)
{
	int		i;

	table->nbr_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->meals_limit = ft_atoi(argv[5]);
	table->start_simulation = 0;
	table->end_simulation = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	pthread_create(&table->watcher, NULL, monitor, table);
	pthread_detach(table->watcher);
	init_philo(table);
	/*i = 0;
	while (i < table->nbr_philo)
    {
		table->philos[i] = (t_philo){0};
        table->philos[i].index = i + 1;
        table->philos[i].fork = i + 1;
        table->philos[i].mutex_fork = table->philos[i].mutex_fork;
        table->philos[i].table = table;
		//printf("philo stop-> %ld\n", table->philos[i].stop);
		//printf("philo death-> %ld\n", table->philos[i].death);
		pthread_mutex_init(&table->philos[i].mutex_fork, NULL);
        pthread_create(&table->philos[i].thread_id, NULL, routine, &table->philos[i]);
		i++;
    }*/
	i = 0;
	while (i < table->nbr_philo)
	{
        pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	free(table->philos);
}