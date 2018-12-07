/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:01:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 22:38:14 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "math.h"

# define WIN_X 1000
# define WIN_Y 1000

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int new_x;
	int new_y;
	int new_z;
}				t_point;

typedef struct	s_system
{
	t_point	**points;
	int		max_x;
	int		max_y;
	int		max_z;
}				t_system;

typedef struct	s_mlx
{
	void	*ptr;
	void	*window;
}				t_mlx;				

typedef struct	s_fdf
{
	char		*map;
	t_mlx		mlx;
	t_system	system;
}				t_fdf;

void error(char *message);
void init(t_fdf *fdf);
void parse(t_fdf fdf, char *map_name);
void show(t_fdf);

#endif