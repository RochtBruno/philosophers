/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:41:56 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/20 15:54:10 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
