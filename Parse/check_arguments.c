/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:24 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/28 13:23:22 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

char	*valid_input(char *str)
{
	int		len;
	char	*nbr;

	len = 0;
	while (*str && *str == ' ')
		++str;
	if (*str == '+')
		++str;
	if (*str == '-')
		print_error(RED"Negative numbers aren't accepted\n");
	if (!(*str >= '0' && *str <= '9'))
		print_error(RED"Not a correct number!\n");
	nbr = str;
	while (*str++ >= '0' && *str++ <= '9')
		len++;
	if (len > 10)
		print_error(RED"Number too big\n");
	return (nbr);
}

int	check_arguments(char **argv)
{
	if ((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[1]) > 200))
	{
		print_error(RED"Put only 1-200 philosophers\n");
		return (0);
	}
	if (ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
	{
		print_error(RED"Timestamps needs to be greater than 60\n");
		return (0);
	}
	return (1);
}
