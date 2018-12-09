/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:53:17 by vduong            #+#    #+#             */
/*   Updated: 2018/12/09 19:54:23 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf *fdf;

	
	if (argc < 2)
		error("Usage : ./fdf [MAP.fdf]\n");
	if (argc > 2)
		error("Only one argument is accepted\n");
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		error("Malloc failed\n");
	init(fdf, argv[1]);
	ft_putstr("init ok\n");
	show(fdf);
	return (0);
}
