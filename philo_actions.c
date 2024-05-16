/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:41:56 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/16 16:42:49 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoh.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_stop);
	if(philo->table->end_simulation == 1)
		return(pthread_mutex_unlock(&philo->table->mutex_stop), 1);
	if(philo->time_to_death <= timestamp())
	{
		philo->death = 1;
		pthread_mutex_unlock(&philo->table->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex_stop);
	return (0);
}

int		wait_philo(t_philo *philo, long time_action)
{
	long	time_to_wait;

	time_to_wait = timestamp() + time_action;
	while(time_to_wait > timestamp())
	{
		if(is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

int		philo_sleep(t_philo *philo)
{
	print_action(philo,"dormindo de cria");
	return (wait_philo(philo,philo->table->time_sleep));
}