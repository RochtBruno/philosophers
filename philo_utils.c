/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:42:08 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 13:34:34 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->gate);
	if (philo->table->philo_must_eat <= 0)
	{
		pthread_mutex_unlock(&philo->table->gate);
		return (1);
	}
	if (philo->eat_count >= philo->table->philo_must_eat)
	{
		pthread_mutex_unlock(&philo->table->gate);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->gate);
	return (1);
}

int	check_philos_eat_count(t_philo *philos)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < philos->table->num_philos)
	{
		pthread_mutex_lock(&philos[i].table->gate);
		if (philos[i].eat_count >= philos[i].table->philo_must_eat)
		{
			ret++;
			if (ret >= philos[i].table->num_philos)
			{
				pthread_mutex_unlock(&philos[i].table->gate);
				return (1);
			}
		}
		pthread_mutex_unlock(&philos[i].table->gate);
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_table *table)
{
	if (table->philo_must_eat > 0 && check_philos_eat_count(table->philos))
	{
		pthread_mutex_lock(&table->gate);
		table->finished = 1;
		return (1);
	}
	return (0);
}
