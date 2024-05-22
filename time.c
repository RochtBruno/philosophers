/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:43:34 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 16:08:55 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time,NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int		wait_philo(t_philo *philo, int time_action)
{
	int	time_to_wait;

	time_to_wait = timestamp() + time_action;
	while(time_to_wait > timestamp())
	{
		if(is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}