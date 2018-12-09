/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:25:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 12:08:23 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace(t_fdf *fdf, t_point a, t_point b)
{
	t_delta	delta;

	delta.dx = abs(b.real_x - a.real_x);
	delta.dy = abs(b.real_y - a.real_y);
	if (delta.dy < delta.dx)
		trace_inferior(fdf, a, b, delta);
	else if (delta.dx == delta.dy)
		trace_equal(fdf, a, b);
	else
		trace_superior(fdf, a, b, delta);
}