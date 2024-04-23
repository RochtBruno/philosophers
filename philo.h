/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:31:48 by btaveira          #+#    #+#             */
/*   Updated: 2024/04/23 16:40:11 by btaveira         ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

typedef struct s_table
{
	int		nbr_philo;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	meals_limit;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}		t_table;

typedef struct s_philo
{
	int			id;
	long		nbr_meals;
	bool		full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}		t_philo;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}		t_fork;


/*------------------PROTO----------------------*/
void	print_error(char	*error);
void	check_arguments(t_table *table, char **argv);

#endif
