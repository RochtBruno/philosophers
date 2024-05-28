/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:06 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/28 13:23:54 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	philo_sleep(t_philo *philo)
{
	int	table_finish;

	table_finish = 0;
	pthread_mutex_lock(&philo->table->gate);
	if (!philo->table->finished)
		printf("%ld %d is sleeping\n",
			get_formatted_time(philo->table->start_time), philo->index + 1);
	table_finish = philo->table->finished;
	pthread_mutex_unlock(&philo->table->gate);
	mspleep(philo->table->time_to_sleep);
	return (table_finish);
}
