/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:33:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/20 20:24:14 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void		ft_line(t_var p1, t_var p2, t_fdf *fdf)
{
	t_line	line;
	line.diffx = 0;
	line.diffy = 0;
	line.sx = ft_sign(p2.x - p1.x);
	line.sy = ft_sign(p2.y - p1.y);
	p1.x *= fdf->zoom;
	p1.y *= fdf->zoom;
	p2.x *= fdf->zoom;
	p2.y *= fdf->zoom;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.x, p1.y, fdf->m_color);
		line.dx = abs(p2.x - p1.x);
		line.dy = abs(p2.y - p1.y);
		line.diffx = line.diffx + (line.dx / line.dy);
		line.diffy = line.diffy + (line.dy / line.dx);
		p1.x += (line.dx < line.dy ? line.diffx >= 1 : 1) * line.sx;
		p1.y += (line.dx > line.dy ? line.diffy >= 1 : 1) * line.sy;
		if (line.diffx >= 1)
			line.diffx -= 1;
		if (line.diffy >= 1)
			line.diffy -= 1;
	}
}

void	draw_parallel(t_fdf *fdf)
{
	t_var	var;
	t_var	pt;

	var.x = 0;
	fdf->m_color = WHITE;
	while (var.x < fdf->width - 1)
	{
		var.y = 0;
	
		while (var.y < fdf->hieght - 1)
 		{	
			if (fdf->map_table[var.y][var.x].v != 0  && fdf->map_table[var.y][var.x + 1].v != 0)
				fdf->m_color = PINK;
			else
				fdf->m_color = WHITE;
			pt.x = var.x + 1;
			pt.y = var.y;
			if (pt.x < fdf->width - 1)
				ft_line(var, pt, fdf);
			pt.x = var.x;
			pt.y = var.y + 1;
			if (fdf->map_table[var.y][var.x].v != 0 && fdf->map_table[var.y + 1][var.x].v != 0)
				fdf->m_color = PINK;
			else
				fdf->m_color = WHITE;
			if (pt.y < fdf->hieght - 1)
				ft_line(var, pt, fdf);
			var.y++;
		}
		var.x++;
	}
}

void	home(void)
{
	// afficher FDF
	// afficher option 1;
	//afficher option 2;
	// keep changing colors
}