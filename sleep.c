/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:44:26 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:00 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_sleep(t_philo *philo)
{
	print_action(philo,"is sleeping");
	return (wait_philo(philo,philo->table->time_sleep));
}