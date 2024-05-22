/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:44:53 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 17:59:16 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	single_fork(t_philo *philo, int fork_index, char *message)
{
	pthread_mutex_lock(&philo[fork_index].mutex_fork);
	//if(philo->index == 1)
		//printf("philo-> %ld fork[%d]-> %d\n",philo->index,fork_index,philo[fork_index].fork);
	if(philo[fork_index].fork == 1)
	{
		philo[fork_index].fork = 0;
		pthread_mutex_unlock(&philo[fork_index].mutex_fork);
		philo->nbr_fork++;
		print_action(philo,message);
		return (1);
	}
	pthread_mutex_unlock(&philo[fork_index].mutex_fork);
	return (0);
}*/

int	get_first_fork(t_philo *philo)
{
	int	first_fork;

	first_fork = philo->index;
	pthread_mutex_lock(&philo[first_fork].mutex_fork);
	if(!(philo->table->end_simulation == 1))
	{
		pthread_mutex_lock(&philo->table->mutex_print);
		print_action(philo,"has taken a fork (first)");
		pthread_mutex_unlock(&philo->table->mutex_print);
	}
	return (first_fork);
}

int	get_second_fork(t_philo *philo)
{
	int	second_fork;

	second_fork = (philo->index + 1) % philo->table->nbr_philo;
	pthread_mutex_lock(&philo[second_fork].mutex_fork);
	if(!(philo->table->end_simulation == 1))
	{
		pthread_mutex_lock(&philo->table->mutex_print);
		print_action(philo,"has taken a fork (second)");
		pthread_mutex_unlock(&philo->table->mutex_print);
	}
	return (second_fork);
}

int	get_forks(t_philo *philo, int *fork_index)
{
	if (philo->table->nbr_philo == 1)
	{
		wait_philo(philo,philo->table->time_die);
		return (0);
	}
	if ((philo->index + 1) == philo->table->nbr_philo)
	{
		fork_index[0] = get_second_fork(philo);
		fork_index[1] = get_first_fork(philo);
	}
	else
	{
		fork_index[0] = get_first_fork(philo);
		fork_index[1] = get_second_fork(philo);
	}
	return (1);
}

/*int take_forks(t_philo *philo)
{
	int		left_fork = philo->left_fork;
	int		right_fork = philo->right_fork;
	long	start_time = philo->table->start_simulation;

	if (is_dead(philo))
		return (0);
	while(philo->nbr_fork < 2)
	{
		if(philo->nbr_fork == 0)
			single_fork(philo,left_fork,"has taken a fork(left)");
		else
			single_fork(philo,right_fork,"has taken a fork(right)");
		if(is_dead(philo) || (timestamp() - start_time) >= philo->table->time_die)
		{
			return_forks(philo);
			print_action(philo, "died");
			return (0);
		}
	}
	if(is_dead(philo) || (timestamp() - start_time) >= philo->table->time_die)
	{
		return_forks(philo);
		print_action(philo, "died");
		return (0);
	}
	return (1);
}*/

int	return_forks(t_philo *philo,int first_fork,int second_fork)
{
	/*int	arr[2];
	arr[0] = philo->left_fork;
	arr[1] = philo->right_fork;
	while(philo->nbr_fork)
	{
		pthread_mutex_lock(&philo[arr[philo->nbr_fork - 1]].mutex_fork);
		philo[arr[philo->nbr_fork - 1]].fork = 1;
		pthread_mutex_unlock(&philo[arr[philo->nbr_fork - 1]].mutex_fork);
		philo->nbr_fork--;
	}*/
	if ((philo->index + 1) == philo->table->nbr_philo)
	{
		pthread_mutex_unlock(&philo[second_fork].mutex_fork);
		pthread_mutex_unlock(&philo[first_fork].mutex_fork);
	}
	else
	{
		pthread_mutex_unlock(&philo[first_fork].mutex_fork);
		pthread_mutex_unlock(&philo[second_fork].mutex_fork);
	}
	return (1);
}

int	eat_philo(t_philo *philo)
{
	/*if(!take_forks(philo))
			return (0);
	print_action(philo, "is eating");
	philo->time_to_death = timestamp() + philo->table->time_die;
	philo->eaten++;
	wait_philo(philo, philo->table->time_eat);
	return_forks(philo);
	return (1);*/
	int	table_end = 0;
	int	forks[2] ;

	if(!get_forks(philo,forks))
		return (table_end);
	pthread_mutex_lock(&philo->table->mutex_print);
	print_action(philo,"is eating\n");
	pthread_mutex_unlock(&philo->table->mutex_print);
	philo->time_to_death = timestamp() + philo->table->time_die;
	philo->eaten++;
	table_end = philo->table->end_simulation;
	wait_philo(philo,philo->table->time_eat);
	return_forks(philo,forks[0],forks[1]);
	return(table_end);
}

int	have_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_eat);
	if(philo->eaten == philo->table->meals_limit)
	{
		philo->table->eaten--;
		if(!philo->table->eaten)
		{
			pthread_mutex_unlock(&philo->table->mutex_eat);
			pthread_mutex_lock(&philo->table->mutex_stop);
			philo->philo_ate = 1;
			pthread_mutex_unlock(&philo->table->mutex_stop);
		}
		else
			pthread_mutex_unlock(&philo->table->mutex_eat);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->mutex_eat);
	return (1);
}