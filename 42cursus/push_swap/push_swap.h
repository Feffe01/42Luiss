#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#	include <stdbool.h>
#	include <limits.h>
# include "libft/libft.h"

	typedef struct s_node
	{
		int						nbr;
		int						index;
		int						push_cost;
		bool					above_median;
		bool					cheapest;
		struct s_node	*target;
		struct s_node	*next;
		struct s_node	*prev;
	} t_node;

	void		error_exit(t_node **a, t_node **b);

	t_node	*create_node(int nbr);
	t_node	*last_node(t_node *lst);
	void		add_node_start(t_node **lst, t_node *new);
	void		add_node_end(t_node **lst, t_node *new);
	t_node	*rm_first_node(t_node **lst);
	t_node	*rm_last_node(t_node **lst);
	int			stack_size(t_node *lst);
	void		free_stack(t_node **lst);

	int			check_int(t_node **lst, char *str);
	void		check_duplicates(t_node **lst);
	void		check_order(t_node **lst);

	void		push_a(t_node **a, t_node **b);
	void		push_b(t_node **a, t_node **b);
	void		swap_a(t_node **a);
	void		swap_b(t_node **b);
	void		swap_both(t_node **a, t_node **b);
	void		rotate_a(t_node **a);
	void		rotate_b(t_node **b);
	void		rotate_both(t_node **a, t_node **b);
	void		rev_rotate_a(t_node **a);
	void		rev_rotate_b(t_node **b);
	void		rev_rotate_both(t_node **a, t_node **b);

#endif
