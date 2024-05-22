/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:13 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/20 15:55:00 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc,char **argv)
{
	t_table	table;

	if(argc == 5 || argc == 6)
	{
		check_arguments(&table, argv);
		init_mutexes(&table);
		data_init(&table,argv);
		//leaks - > philos full || 1 philo died
		//clean_table(&table);
	}
	else
		print_error(RED"INVALID ARGUMENTS\n");
}