/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:31:36 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/19 17:15:45 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	signal;


	i = 0;
	res = 0;
	signal = 1;

	if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signal);
}

int	only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int	argc,char **str)
{
	int	i;

	i = 1;
	while (i <= argc && str[i])
	{
		if(only_number(str[i]) == 0)
		{
			printf("only numbers are accepted\n");
			return (1);
		}
		if(ft_atoi(str[i]) <= 0)
		{
			printf("zero and negative numbers aren't accepted\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_philo_data(t_philo *philo)
{
		if(philo->nb_philo > 200)
		{
			printf("DO NOT TEST WITH MORE THAN 200 PHILOSOPHERS");
			return (1);
		}
		if(philo->time_to_die < 60 || philo->time_to_eat < 60 || philo->time_to_sleep < 60)
		{
			printf("TIME NEEDS TO BE AT LEAST 60");
			return(1);
		}
		if(philo->must_eat == 0)
		{
			printf("THE PHILOSOPHERS MUST EAT AT LEAST 1 TIME");
			return(1);
		}
		return (0);
}