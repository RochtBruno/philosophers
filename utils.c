/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:31:14 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 13:31:17 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	get_formatted_time(time_t start_time)
{
	return (get_current_time() - start_time);
}

void	mspleep(time_t time_sleep)
{
	time_t	time;

	time = get_current_time();
	while (get_current_time() - time < time_sleep)
		usleep(100);
}

int	ft_atoi(char *str)
{
	int	res;

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
