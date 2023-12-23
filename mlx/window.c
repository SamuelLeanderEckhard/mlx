/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:26:19 by seckhard          #+#    #+#             */
/*   Updated: 2023/12/23 19:31:32 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

int	main()
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (NULL == mlx_connection)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_connection,
								HEIGHT,
								WIDTH,
								"My window");
	if (NULL == mlx_window)
    {
        mlx_destroy_display(mlx_connection); // Cleanup MLX connection
        free(mlx_connection);
        return (MALLOC_ERROR);
    }
	mlx_loop(mlx_connection); mlx_ptr:


	/*
	 * 🚨 CLEAN UP is never reached due to the loop 🚨
	 * 		If i press control-C i will get LEAKS
	 *
	 * 		💡 i need EVENTs handling for that...💡
	*/
	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}