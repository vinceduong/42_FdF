/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:39:29 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 19:36:45 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void show(t_fdf *fdf)
{
	ft_putstr("in show\n");
	if (!(fdf->mlx.ptr = mlx_init("FDF")))
		error("mlx_init failed\n");
	ft_putstr("Mlx init ok\n");
	fdf->mlx.window = mlx_new_window(fdf->mlx.ptr, WIN_X, WIN_Y, "FdF");
	ft_putstr("mlx init\n");
	set_real_coor(fdf);
	ft_putstr("ok1\n");
	print_points(fdf);
	ft_putstr("ok2\n");
	put_lines(fdf);
	mlx_loop(fdf->mlx.ptr);
}