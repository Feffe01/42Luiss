/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:41 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/18 01:11:18 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (1);
	initializer(argc, argv, &data);
	start_threads(&data);
	free_fork_list(data.fst_fork);
	free_philo_list(data.fst_philo);
	return (0);
}
