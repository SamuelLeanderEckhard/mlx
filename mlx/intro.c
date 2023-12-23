/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:08:58 by seckhard          #+#    #+#             */
/*   Updated: 2023/12/23 19:21:36 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (NULL == mlx_ptr)
		return (1);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}