/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_inferior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:46:39 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 12:07:41 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_inferior(t_fdf *fdf, t_point a, t_point b, t_delta delta)
{
	int inc_x;
	int inc_y;
	int error;

	inc_x = b.real_x - a.real_x > 0 ? 1 : -1;
	inc_y = b.real_y - a.real_y > 0 ? 1 : -1;
	error = delta.dx;
	delta.dx *= 2;
	delta.dy *= 2;
	while (a.real_x != b.real_x)
	{
		if (a.real_x >= 0 && a.real_x <= WIN_X && a.real_y >= 0 && a.real_y <= WIN_Y)
			mlx_pixel_put(fdf->mlx.ptr, fdf->mlx.window, a.real_x, a.real_y, WHITE);
		error -= delta.dy;
		if (error < 0)
		{
			a.real_y+= inc_y;
			error += delta.dx;
		}
		a.real_x += inc_x;
	}
	if (a.real_x >= 0 && a.real_x <= WIN_X && a.real_y >= 0 && a.real_y <= WIN_Y)
		mlx_pixel_put(fdf->mlx.ptr, fdf->mlx.window, a.real_x, a.real_y, WHITE);
}