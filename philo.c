/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:28:03 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/18 17:09:50 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if(argc != 5 && argc != 6)
	{
		printf("!!INVALID ARGUMENTS!!\n");
                printf("<PHILOSOPHERS> <DIE> <EAT> <SLEEP> (<MUST EAT>)\n");
	}

	if(argc == 5)
	{
		int	i;

		i = 1;
		while (i <= argc && argv[i])
		{
			if(only_number(argv[i]) == 0)
			{
				printf("only numbers are accepted\n");
				return (1);
			}
			if(ft_atoi(argv[i]) <= 0)
			{
				printf("zero and negative aren't accepted\n");
				return(1);
			}
			i++;
		}
	}

	if(argc == 6)
	{
		int	i;

		i = 1;
		while(i <= argc && argv[i])
		{
			if(only_number(argv[i]) == 0)
				printf("only numbers are accepted\n");
			else if(ft_atoi(argv[i]) <= 0)
				printf("zero and negative aren't accepted\n");
			i++;
		}
		
	}
}
