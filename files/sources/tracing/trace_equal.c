/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:46:42 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 11:16:55 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_equal(t_fdf *fdf, t_point a, t_point b)
{
	int inc_x;
	int inc_y;
	int x;
	int y;

	inc_x = b.real_x - a.real_x > 0 ? 1 : -1;
	inc_y = b.real_y - a.real_y > 0 ? 1 : -1;
	x = a.real_x;
	y = a.real_y;
	while (x != b.real_x)
	{
		if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
			mlx_pixel_put(fdf->mlx.ptr, fdf->mlx.window, x, y, WHITE);
		x += inc_x;
		y += inc_y;
	}
	if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
		mlx_pixel_put(fdf->mlx.ptr, fdf->mlx.window, x, y, WHITE);
}