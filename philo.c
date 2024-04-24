/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:13 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/24 13:42:11 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc,char **argv)
{
	t_table	table;

	if(argc == 5 || argc == 6)
	{
		//start  - check input before putting into table
		//put_input(&table,argv);
		check_arguments(&table, argv);
		//printf("philos-> %d\ndie-> %ld\neat-> %ld\nsleep-> %ld\n",table.nbr_philo,table.time_die,table.time_eat,table.time_sleep);
		//data_init(&table);

		//start_dinner(&table);

		//leaks - > philos full || 1 philo died
		//clean_table(&table);
	}
	else
		print_error(RED"INVALID ARGUMENTS\n");
}