/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:30:20 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 12:02:28 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init(t_fdf *fdf, char *filename)
{
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		error("Malloc failed\n");
	parse(fdf, filename);
	fdf->mlx.ptr = mlx_init();
	fdf->mlx.window = mlx_new_window(fdf->mlx.ptr, WIN_X, WIN_Y, "FdF");
	fdf->points[0][1].real_x = 0;
 	fdf->points[0][1].real_y = 0;
	fdf->points[0][2].real_x = 100;
 	fdf->points[0][2].real_y = 1000;
	trace(fdf, fdf->points[0][2], fdf->points[0][1]);
	mlx_loop(fdf->mlx.ptr);
}