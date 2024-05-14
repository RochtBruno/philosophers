/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:31:48 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/14 16:26:15 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

/*ERROR MESSAGES COLORS*/

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

/*-------------STRUCTS-------------*/

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long	nbr_philo;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	meals_limit;
	long	start_simulation;
	bool	end_simulation;
	t_philo	*philos;
}		t_table;

typedef struct s_philo
{
	int			index;
	int			fork;
	long		nbr_meals;
	bool		full;
	long		last_meal_time;
	pthread_t	thread_id;
	pthread_mutex_t		mutex_fork;
	t_table		*table;
}		t_philo;



/*------------------PROTO----------------------*/
void	print_error(char	*error);
void	check_arguments(t_table *table, char **argv);
void	data_init(t_table *table,char **argv);
long		ft_atoi(char *str);
char	*valid_input(char *str);

#endif
