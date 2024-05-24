/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:31:22 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/24 13:36:55 by btaveira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					index;
	time_t				last_time_eat;
	int					eat_count;
	t_table				*table;
	pthread_t			thread;
}						t_philo;

typedef struct s_table
{
	time_t				start_time;
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					philo_must_eat;
	int					finished_eating;
	int					finished;
	t_philo				*philos;
	pthread_t			watcher;
	pthread_mutex_t		gate;
	pthread_mutex_t		*forks;
}						t_table;

int						create_philos(t_table *table);

// philo operations
int						philo_think(t_philo *philo_data);
int						philo_eat(t_philo *philo_data);
int						philo_sleep(t_philo *philo_data);
void					create_watcher(t_table *table);

// philo forks
int						get_first_fork(t_philo *philo);
int						get_second_fork(t_philo *philo);
int						get_forks(t_philo *philo, int *forks_pointer);
int						release_forks(int first_fork, int second_fork,
							t_philo *philo);
void					free_forks(pthread_mutex_t *forks, int num_philos);

// time utils
time_t					get_current_time(void);
time_t					get_formatted_time(time_t start_time);
void					mspleep(time_t time);

// utils
int						check_eat_count(t_philo *philo);
int						check_if_all_ate(t_table *table);
int						ft_atoi(char *str);
char					*valid_input(char *str);
int						check_arguments(char **argv);
void					print_error(char	*error);

#endif
