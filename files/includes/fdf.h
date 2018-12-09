/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:01:16 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 12:00:24 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <fcntl.h>
# include <stdio.h>

# define WIN_X 1000
# define WIN_Y 1000
# define WHITE 0xFFFFFF
typedef struct	s_mlx
{
	void	*ptr;
	void	*window;
}				t_mlx;				

typedef struct s_point
{
	int x;
	int y;
	int z;
	int real_x;
	int real_y;
}				t_point;

typedef struct s_delta
{
	int	dx;
	int dy;
}				t_delta;

typedef struct	s_fdf
{
	char		**map;
	t_point		**points;
	t_mlx		mlx;
	int			x; 
	int			y;
	int			unit;
	float		phi;
	float		teta;
}				t_fdf;

/*
*** PARSE
*/

void	error(char *message);
void	init(t_fdf *fdf, char *map_name);
void	parse(t_fdf *fdf, char *map_name);
void	show(t_fdf);
void	check_map(t_fdf *fdf);
void	fill_points(t_fdf *fdf);

/*
*** TRACE
*/

void	trace(t_fdf *fdf, t_point a, t_point b);
void	trace_equal(t_fdf *fdf, t_point a, t_point b);
void	trace_inferior(t_fdf *fdf, t_point a, t_point b, t_delta delta);
void	trace_superior(t_fdf *fdf, t_point a, t_point b, t_delta delta);

#endif