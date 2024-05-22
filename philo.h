/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:31:48 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/22 17:59:05 by btaveira         ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef struct s_philo
{
	int		index;
	int		nbr_fork;
	int		fork;
	int		left_fork;
	int		right_fork;
	int		nbr_meals;
	int		full;
	int		eaten;
	int		death;
	int		time_to_death;
	int		philo_stop;
	int		philo_died;
	int		philo_ate;
	pthread_t	thread_id;
	pthread_mutex_t		mutex_fork;
	t_table		*table;
}		t_philo;

typedef struct s_table
{
	int				eaten;
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_limit;
	int				start_simulation;
	int				end_simulation;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_eat;
	pthread_t	watcher;
	t_philo	*philos;
}		t_table;

/*------------------PROTO----------------------*/
void	print_error(char	*error);
void	check_arguments(t_table *table, char **argv);
void	data_init(t_table *table,char **argv);
void	init_mutexes(t_table *table);
void	print_action(t_philo *philo, char *action);
void	init_mutexes(t_table *table);
int	return_forks(t_philo *philo,int first_fork,int second_fork);
void	init_philo(t_table *table);
void	*routine(void *arg);
void	*monitor(void *arg);
int	ft_atoi(char *str);
int	timestamp(void);
char	*valid_input(char *str);
int		is_dead(t_philo *philo);
int		wait_philo(t_philo *philo, int time_action);
int		philo_sleep(t_philo *philo);
int		have_eaten(t_philo *philo);
int		eat_philo(t_philo *philo);
int		get_forks(t_philo *philo, int *fork_index);
int		single_fork(t_philo *philo, int fork_index, char *message);

#endif
