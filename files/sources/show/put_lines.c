/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:15:17 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 20:33:04 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_lines(t_fdf *fdf)
{
	int i;
	int j;
	
	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			if (j < fdf->x - 1)
				trace(fdf, fdf->points[i][j], fdf->points[i][j + 1]);
			if (i < fdf->y - 1)
				trace(fdf, fdf->points[i][j], fdf->points[i + 1][j]);
			j++;
		}
		i++;
	}
}