/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:30:20 by vduong            #+#    #+#             */
/*   Updated: 2018/12/10 10:00:13 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void init(t_fdf *fdf, char *filename)
{
	parse(fdf, filename);
	fdf->unit = (float)(WIN_X - PADDING) / (float)max(fdf->x, fdf->y);
	ft_putstr("OK\n");
	fdf->phi = M_PI_2 / 4;
	fdf->teta = 0.2;
}