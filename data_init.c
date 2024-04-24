/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:13:16 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/24 14:26:42 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	attach_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->nbr_philo;
	philo->first_fork = &forks[(position + 1) % philo_nbr];
	philo->second_fork = &forks[position];
	if(philo->id % 2 == 0)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % philo_nbr];
	}

}

static	void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;
	i = 0;
	while(i < table->nbr_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		philo->table = table;
		attach_forks(philo, table->forks, i);
		i++;
	}
}

void	data_init(t_table *table)
{
	int		i;

	i = 0;
	table->end_simulation = false;
	table->nbr_philo = malloc(sizeof(t_philo) * table->nbr_philo);
	table->forks = malloc(sizeof(t_fork) * table->forks);
	while(i < table->nbr_philo)
	{
		pthread_mutex_init(&table->forks[i]);
		table->forks[i].fork_id = i;
		i++;
	}
	philo_init(&table);
}