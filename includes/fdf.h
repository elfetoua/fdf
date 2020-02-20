/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:01:30 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/20 23:58:10 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <math.h>

#include <stdio.h>

#include "mlx.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"
#define RED 0x00ff0000
#define ORANGE 0X00FFA500
#define WHITE 0X00FFFFFF
#define YELLOW 0X00FFFF00
#define AQUA 0X0000FFFF
#define PINK 0X00FF00FF
#define GREEN 0X0000FF00

typedef	struct	s_point
{
    int		v;
	int		color;
}				t_point;

typedef	struct	s_fdf
{
    int		hieght;
    int		width;
	int		zoom;
	int     m_color;
    t_point	**map_table;
	
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

typedef	struct	s_var
{
    int		x;
	int		y;
	int		z; /*/*/
}				t_var;

typedef	struct			s_line
{
	double				dx;
	double				dy;
	int					sx;
	int					sy;
	double				diffx;
	double				diffy;
}						t_line;

void	read_file(char *, t_fdf *);
void	map_dimensions(char *, int*, int*);
void	get_values(t_point *, char *);
int		hexTodec(char *);
void    draw_parallel(t_fdf *);
void	home(void);
void	draw_iso(t_fdf *, t_var);
#endif