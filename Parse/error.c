/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:31:45 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/28 13:23:44 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

void	print_error(char *error)
{
	printf(RED"%s\n", error);
	printf(G"USAGE: <PHILO> <DIE> <EAT> <SLEEP> [LIMIT_MEALS]\n");
	return ;
}
