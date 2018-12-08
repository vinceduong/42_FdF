/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:15:17 by vduong            #+#    #+#             */
/*   Updated: 2018/12/08 10:20:18 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	(void)fdf;
}