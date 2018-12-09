/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_real_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:35:02 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 18:31:42 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_real_coor(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->points[j][i].real_x = i * fdf->points[j][i].x;
			fdf->points[j][i].real_y = i * fdf->points[j][i].y;
			j++;
		}
		i++;
	}
}