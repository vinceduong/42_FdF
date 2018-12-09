/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_real_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:35:02 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 21:37:43 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_real_coor(t_fdf *fdf)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->points[i][j].real_x = (fdf->unit / 2) * fdf->points[i][j].x;
			fdf->points[i][j].real_y = (fdf->unit / 2) * fdf->points[i][j].y;
			tmp = fdf->points[i][j].real_y;
			fdf->points[i][j].real_y += tan(fdf->phi) * fdf->points[i][j].real_x + fabs(sin(fdf->phi) * (fdf->points[i][j].z * (fdf->unit / 2)));
			fdf->points[i][j].real_x += tan(fdf->teta) * tmp + fabs(cos(fdf->phi) * (fdf->points[i][j].z * (fdf->unit / 2)));
			j++;
		}
		i++;
	}
}