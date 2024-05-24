/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:24 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 13:35:24 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher_day(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	i = 0;
	while (1)
	{
		if (check_if_all_ate(table))
			break ;
		pthread_mutex_lock(&table->gate);
		if (get_current_time()
			- table->philos[i].last_time_eat > table->time_to_die)
		{
			if (!table->finished)
				printf("%ld %d died\n", get_formatted_time(table->start_time), i
					+ 1);
			table->finished = 1;
			break ;
		}
		i = (i + 1) % table->num_philos;
		pthread_mutex_unlock(&table->gate);
	}
	pthread_mutex_unlock(&table->gate);
	usleep(1000);
	return (NULL);
}

void	create_watcher(t_table *table)
{
	if (pthread_create(&table->watcher, NULL, &watcher_day, table) != 0)
		printf("Error: pthread_create\n");
	if (pthread_join(table->watcher, NULL) != 0)
		printf("Error: pthread_join\n");
}