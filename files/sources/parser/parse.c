/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:15:17 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 19:58:44 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->y)
		{
			printf(" [%d, %d, %d, %d, %d] ", fdf->points[i][j].x, fdf->points[i][j].y, fdf->points[i][j].z, fdf->points[i][j].real_x, fdf->points[i][j].real_y);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	parse(t_fdf* fdf, char *map_name)
{
	int fd;
	char *line;
	char *map;

	if((fd = open(map_name, O_RDONLY)) < 0)
		error("Can't open map\n");
	line = NULL;
	if (!(map = ft_strnew(1)))
		error("Malloc failed\n");
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
		ft_strdel(&line);
	}
	fdf->map = ft_strsplit(map, '\n');
	check_map(fdf);
	printf("y = %d, x = %d\n", fdf->y, fdf->x);
	fill_points(fdf);
	print_points(fdf);
}