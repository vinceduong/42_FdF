/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:43:17 by vduong            #+#    #+#             */
/*   Updated: 2018/12/08 14:34:32 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fill_points(t_fdf *fdf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!(fdf->points = malloc(sizeof(t_point *) * fdf->y)))
		error("Malloc failed\n");
	while (i < fdf->y)
	{
		if (!(fdf->points[i] = malloc(sizeof(t_point) * fdf->x)))
			error("Malloc failed\n");
		j = 0;
		tmp = fdf->map[i];
		while (*tmp)
		{
			fdf->points[i][j].z = ft_atoi(tmp);
			fdf->points[i][j].x = j;
			fdf->points[i][j].y = i;
			j++;
			tmp++;
			while (*tmp && *tmp != ' ')
				tmp++;
		}
		i++;
	}
}