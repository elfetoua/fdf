/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:56:33 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/17 12:28:06 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdlib.h>

typedef	struct
{
    int		i;
    int		j;
    double		x;
	double		y;
}				s_var;

void	draw_line(s_var pt1, s_var pt2, void *mlx_ptr, void *win_ptr)
{
	double	dx;
	double	dy;
	int	k;
    int max;
    double x_inc;
    double  y_inc;

	
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	if(fabs(dx) > fabs(dy))
        max = fabs(dx);
    else
    {
        max = fabs(dy);
    }
    x_inc = dx / max;
    y_inc = dy / max;
    
    
	while (k <= max)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, round(pt1.x), round(pt1.y), 0x00ff0000);
        pt1.x += x_inc;
        pt1.y += y_inc;
        k++;
	}
}

int main()
{
    s_var pt1;
    s_var pt2;

    pt1.x = 10;
    pt2.x = 400;
    pt1.y = 5;
    pt2.y = 300;
    void*   mlx_ptr;
    void*   mlx_ptr_win;
    mlx_ptr = mlx_init();
    mlx_ptr_win = mlx_new_window(mlx_ptr, 500, 500, "mehdi");
    draw_line(pt1, pt2, mlx_ptr, mlx_ptr_win);
    mlx_loop(mlx_ptr);
    return 0;
}
