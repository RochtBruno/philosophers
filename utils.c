/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:19:34 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 16:09:16 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char	*error)
{
	printf(RED"%s\n",error);
	printf(G"USAGE: <PHILO> <DIE> <EAT> <SLEEP> [LIMIT_MEALS]\n");
	exit(1);
}

void	print_action(t_philo *philo, char *action)
{
	long	ms;

	ms = timestamp() - philo->table->start_simulation;
	if(philo->philo_stop == 1 || is_dead(philo))
		return;
	pthread_mutex_lock(&philo->table->mutex_print);
	printf("%ld ms ",ms);
	printf("%d %s\n",philo->index, action);
	pthread_mutex_unlock(&philo->table->mutex_print);
}

void	init_mutexes(t_table *table)
{
	pthread_mutex_init(&table->mutex_stop,NULL);
	pthread_mutex_init(&table->mutex_print,NULL);
	pthread_mutex_init(&table->mutex_eat,NULL);
}