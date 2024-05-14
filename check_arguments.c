/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:29:13 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/14 15:00:49 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*valid_input(char *str)
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

long	ft_atoi(char *str)
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
	if((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[1]) > 200))
		print_error(RED"Put only 1-200 philosophers\n");
	if(ft_atoi(argv[2]) < 60
	|| ft_atoi(argv[3]) < 60
	|| ft_atoi(argv[4]) < 60)
		print_error(RED"Timestamps needs to be greater than 60\n");
	if(argv[5])
		table->meals_limit = ft_atoi(argv[5]);
	else
		table->meals_limit = -1;
}