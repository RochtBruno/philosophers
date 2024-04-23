/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:29:13 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/23 16:42:31 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	char	*valid_input(char *str)
{
	int		len;
	char	*nbr;

	len = 0;
	while (*str && *str == ' ')
		++str;
	if(*str == '+')
		++str;
	if(*str == '-')
		print_error(RED"Negative numbers aren't accepted\n");
	if(!(*str >= '0' && *str <= '9'))
		print_error(RED"Not a correct number!\n");
	nbr = str;
	while(*str++ >= '0' && *str++ <= '9')
		len++;
	if(len > 10)
		print_error(RED"Number too big\n");
	return (nbr);
}

static long	ft_atol(char *str)
{
	long	res;

	res = 0;
	str = valid_input(str);
	while(*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > INT_MAX)
		print_error(RED"Number too big\n");
	return (res);
}

void	check_arguments(t_table *table, char **argv)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]) * 1000;
	table->time_eat = ft_atol(argv[3]) * 1000;
	table->time_sleep = ft_atol(argv[4]) * 1000;

	if(table->nbr_philo < 1)
		print_error(RED"Put at least 1 philosopher\n");
	if(table->time_die < 60000
	|| table->time_eat < 60000
	|| table->time_sleep < 60000)
		print_error(RED"Timestamps needs to be greater than 60\n");
	if(argv[5])
		table->meals_limit = ft_atol(argv[5]);
	else
		table->meals_limit = -1;
}