/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:19:34 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/14 14:47:25 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char	*error)
{
	printf(RED"%s\n",error);
	printf(G"USAGE: <PHILO> <DIE> <EAT> <SLEEP> [LIMIT_MEALS]\n");
	exit(1);
}