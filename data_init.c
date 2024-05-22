/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:13:16 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 16:27:01 by btaveira         ###   ########.fr       */
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

void	data_init(t_table *table, char **argv)
{
	int		i;

	table->nbr_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->meals_limit = ft_atoi(argv[5]);
	table->end_simulation = 0;
	table->start_simulation = timestamp();
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	init_philo(table);
	pthread_create(&table->watcher, NULL, monitor, table);
	pthread_detach(table->watcher);
	i = 0;
	while (i < table->nbr_philo)
	{
        pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	free(table->philos);
}