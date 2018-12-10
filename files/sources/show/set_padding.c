/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 08:55:06 by vduong            #+#    #+#             */
/*   Updated: 2018/12/10 10:00:38 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_padding(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->points[i][j].real_x += PADDING * 2; 
			fdf->points[i][j].real_y += PADDING * 2;
			j++;
		}
		i++;
	}
}