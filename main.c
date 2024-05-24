/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:46 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 13:35:59 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc < 5 || argc > 6)
	{
		print_error("Error: Invalid arguments\n");
		return (1);
	}
	check_arguments(argv);
	table.start_time = get_current_time();
	table.num_philos = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table.philo_must_eat = ft_atoi(argv[5]);
	create_philos(&table);
	free(table.philos);
	free_forks(table.forks, table.num_philos);
	return (0);
}
