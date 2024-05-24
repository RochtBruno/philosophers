/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:29 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 12:51:44 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	int	table_finish;
	int	forks[2];

	table_finish = 0;
	if (!get_forks(philo, forks))
		return (table_finish);
	pthread_mutex_lock(&philo->table->gate);
	philo->last_time_eat = get_current_time();
	if (!philo->table->finished)
		printf("%ld %d is eating\n",
			get_formatted_time(philo->table->start_time), philo->index + 1);
	philo->eat_count++;
	table_finish = philo->table->finished;
	pthread_mutex_unlock(&philo->table->gate);
	mspleep(philo->table->time_to_eat);
	release_forks(forks[0], forks[1], philo);
	return (table_finish);
}