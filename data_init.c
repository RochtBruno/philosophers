/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:13:16 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/14 16:41:54 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ceiar routine
void	data_init(t_table *table, char **argv)
{
	int		i;

	table->nbr_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	//table->meals_limit = ft_atoi(argv[5]);
	table->start_simulation = 0;
	table->end_simulation = false;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	i = 0;
	while (i < table->nbr_philo)
    {
        table->philos[i].index = i + 1;
        table->philos[i].nbr_meals = 0;
        table->philos[i].full = false;
        table->philos[i].last_meal_time = 0;
        table->philos[i].fork = i;
        table->philos[i].mutex_fork = table->philos[i].mutex_fork;
        table->philos[i].table = table;
		printf("philo index-> %d\n", table->philos[i].index);
        //pthread_create(&table->philos->thread_id[i], NULL, routine, &table->philos[i]);
		i++;
    }
	i = 0;
	while(i < table->nbr_philo)
		pthread_mutex_init(&table->philos[i++].mutex_fork, NULL);

    // Inicializa os filósofos e inicia as threads
	i = 0;
	while (i < table->nbr_philo)
	{
        pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	free(table->philos);
}