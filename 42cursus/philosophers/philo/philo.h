/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:33:45 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/18 01:14:38 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef enum e_status
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD,
	DONE
}	t_STATUS;

typedef struct s_fork
{
	int				index;
	pthread_mutex_t	mutex;
	struct s_fork	*next;
}	t_fork;

typedef struct s_philo
{
	int				index;
	t_STATUS		status;
	int				num_philos;
	int				time_die;
	long			time_last_eat;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	t_fork			*right_fork;
	t_fork			*left_fork;
	struct s_philo	*next;
	pthread_mutex_t	status_mutex;
	int				stop_sim;
}	t_philo;

typedef struct s_data
{
	int		num_philos;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_meals;
	t_philo	*fst_philo;
	t_fork	*fst_fork;
}	t_data;

/*UTILS*/
int		ft_atoi(const char *str);
void	initializer(int argc, char **argv, t_data *data);
void	stop_simulation(void *first);
void	start_threads(t_data *data);

/*FORKS*/
t_fork	*create_fork(int index);
void	add_fork(t_fork **lst, t_fork *new);
t_fork	*last_fork(t_fork *lst);
t_fork	*find_fork(t_fork *lst, int index);
void	free_fork_list(t_fork *forks);

/*PHILOS*/
t_philo	*create_philo(int index, t_data *data);
void	add_philo(t_philo **lst, t_philo *new);
t_philo	*last_philo(t_philo *lst);
void	free_philo_list(t_philo *philos);

/*ACTIONS*/
void	p_eat(void *philo);
void	p_sleep(void *philo);
void	take_fork_ts(t_philo *p);

/*STATUS CHANGERS*/
void	is_eating_ts(t_philo *p);
void	is_sleeping_ts(t_philo *p);
void	is_thinking_ts(t_philo *p);
void	died_ts(t_philo *p);
void	has_done(t_philo *p);

/*CHECKERS*/
int		check_end(t_philo *p);
int		check_death(void *first);
int		check_done(void *first);

#endif
