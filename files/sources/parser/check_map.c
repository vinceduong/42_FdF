/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:43:30 by vduong            #+#    #+#             */
/*   Updated: 2018/12/08 12:33:47 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_line(char *str_line)
{
	char *tmp;
	char **line;
	int j;
	int i;

	if (!(line = ft_strsplit(str_line, ' ')))
		error("Malloc failed\n");
	j = 0;
	while (line[j])
	{
		tmp = line[j];
		i = 0;
		while (tmp[i])
		{
			if(!ft_isdigit(tmp[i]) && !(i == 0 && tmp[i] == '-' && ft_isdigit(tmp[i + 1])))
				error("Not a valid map\n");
			i++;
		}
		j++;
	}
	return (j);
}
void	check_map(t_fdf *fdf)
{
	char	**map;
	int		y;
	int		x;

	map = fdf->map;
	y = 0;
	x = 0;
	while (map[y])
	{
		if (!x)
		{
			x = check_line(map[y]);
			fdf->x = x;
		}
		else if (x != check_line(map[y]))
			error("Not a valid map\n");
		y++;
	}
	fdf->y = y;
}