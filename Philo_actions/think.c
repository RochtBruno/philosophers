/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:50:44 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/28 13:24:02 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	philo_think(t_philo *philo)
{
	int	table_finish;

	table_finish = 0;
	pthread_mutex_lock(&philo->table->gate);
	if (!philo->table->finished)
		printf("%ld %d is thinking\n",
			get_formatted_time(philo->table->start_time), philo->index + 1);
	table_finish = philo->table->finished;
	pthread_mutex_unlock(&philo->table->gate);
	return (table_finish);
}
