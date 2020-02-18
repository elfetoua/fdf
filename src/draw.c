/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:33:10 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/18 13:03:03 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	bresnham(t_var pt1, t_var pt2, s_fdf *fdf)
// {
// 	double	dx;
// 	double	dy;
// 	int	k;
//     int max;
//     double x_inc;
//     double  y_inc;

	
// 	dx = pt2.x - pt1.x;
// 	dy = pt2.y - pt1.y;
// 	if(fabs(dx) > fabs(dy))
//         max = fabs(dx);
//     else
//     {
//         max = fabs(dy);
//     }
//     x_inc = dx / max;
//     y_inc = dy / max;
    
//     k = 0;
// 	while (k <= max)
// 	{
// 		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, round(pt1.x), round(pt1.y), 0x00ff0000);
//         pt1.x += x_inc;
//         pt1.y += y_inc;
//         k++;
// 	}
// }
int			ft_sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void		ft_line(t_var p1, t_var p2, t_fdf *coor)
{
	t_line	line;
	line.diffx = 0;
	line.diffy = 0;
	line.sx = ft_sign(p2.x - p1.x);
	line.sy = ft_sign(p2.y - p1.y);
	p1.x *= coor->zoom;
	p1.y *= coor->zoom;
	p2.x *= coor->zoom;
	p2.y *= coor->zoom;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		mlx_pixel_put(coor->mlx_ptr, coor->win_ptr, p1.x, p1.y, coor->m_color);
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

void	draw(t_fdf *fdf)
{
	t_var	var;
	t_var	pt;

	var.x = 0;
	fdf->m_color = WHITE;
	while (var.x < fdf->width - 1)
	{
		var.y = 0;
		while (var.y < fdf->hieght - 3)
		{
			if (fdf->map_table[var.x][var.y].v != 0)
				{
					printf("x = %d\n y = %d\n", var.x, var.y);
				}
			pt.x = var.x;
			pt.y = var.y + 1;
			
			ft_line(var, pt, fdf);
			pt.x = var.x + 1;
			pt.y = var.y;
			ft_line(var, pt, fdf);
			var.y++;
		}
		var.x++;
	}
	var.x = 0;
	while(fdf->map_table[var.x])
	{
		var.y = 0;
		while(var.y < fdf->width)
		{
			ft_putendl("value is: ");
			ft_putnbr(fdf->map_table[var.x][var.y].v);
			ft_putstr("\n");
			ft_putendl("color is: ");
			ft_putnbr(fdf->map_table[var.x][var.y].color);
			ft_putstr("\n");
			var.y++;
		}
		var.x++;
	}
}