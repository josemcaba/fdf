/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/07 12:57:29 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx_ptr;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init(500, 600, "FdF (Jose M. Caballero)", true);
	mlx_loop(mlx_ptr);
}
