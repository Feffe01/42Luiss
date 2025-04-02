#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_boolean
{
	FALSE,
	TRUE
} t_bool;

typedef enum e_status
{
	EATING,
	THINKING,
	SLEEPING
} STATUS;

typedef struct s_fork
{
	int		index;
	t_bool	active;
	pthread_mutex_t	mutex;
	struct s_fork	*prev;
	struct s_fork	*next;
} fork_node;

typedef struct s_philo
{
	int			index;
	STATUS		status;
	int		num_philos;
	int		time_die;
	int		time_from_eat;
	int		time_eat;
	int		time_sleep;
	int		num_meals;
	int		actual_meal;
	fork_node	*right_fork;
	fork_node	*left_fork;
	struct s_philo	*prev;
	struct s_philo	*next;
} philo_node;

typedef struct s_data
{
	int		num_philos;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_meals;
	philo_node	*fst_philo;
	fork_node		*fst_fork;
} t_data;

void	initializer(int argc, char **argv, t_data *data);

/*UTILS*/
int	ft_atoi(const char *str);

/*FORKS*/
fork_node	*create_fork_node(int index);
void			add_fork_node(fork_node **lst, fork_node *new);
fork_node	*last_fork_node(fork_node *lst);
fork_node	*find_fork_node(fork_node *lst, int index);
void			free_fork_list(fork_node *forks);

/*PHILOS*/
philo_node	*create_philo_node(int index, t_data *data);
void				add_philo_node(philo_node **lst, philo_node *new);
philo_node	*last_philo_node(philo_node *lst);
void				free_philo_list(philo_node *philos);

#endif
