/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:28:03 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/19 17:18:18 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){0};
	if(argc != 5 && argc != 6)
	{
		printf("!!INVALID ARGUMENTS!!\n");
		printf("<PHILOSOPHERS> <DIE> <EAT> <SLEEP> (<MUST EAT>)\n");
	}

	if(argc == 5)
	{
		if(check_input(argc, argv) == 0)
		{
			philo.nb_philo = ft_atoi(argv[1]);
			philo.time_to_die = ft_atoi(argv[2]);
			philo.time_to_eat = ft_atoi(argv[3]);
			philo.time_to_sleep = ft_atoi(argv[4]);
			philo.must_eat = -1;
		};
		if(check_philo_data(&philo) == 0)
			printf("nb_philo->%d\ndie->%d\neat->%d\nsleep->%d\nmust_eat-> %d\n",philo.nb_philo,philo.time_to_die,philo.time_to_eat,philo.time_to_sleep,philo.must_eat);
	}

	if(argc == 6)
	{
		if(check_input(argc, argv) == 0)
		{
			philo.nb_philo = ft_atoi(argv[1]);
			philo.time_to_die = ft_atoi(argv[2]);
			philo.time_to_eat = ft_atoi(argv[3]);
			philo.time_to_sleep = ft_atoi(argv[4]);
			philo.must_eat = ft_atoi(argv[5]);
		};
		if(check_philo_data(&philo) == 0)
			printf("nb_philo->%d\ndie->%d\neat->%d\nsleep->%d\nmust_eat-> %d\n",philo.nb_philo,philo.time_to_die,philo.time_to_eat,philo.time_to_sleep,philo.must_eat);
	}
}
