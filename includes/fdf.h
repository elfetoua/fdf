/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:01:30 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/16 01:51:36 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef	struct
{
    int		v;
	int		color;
}				s_point;

typedef	struct
{
    int		hieght;
    int		width;
    s_point	**map_table;
	
	void	*mlx_ptr;
	void	*win_ptr;
}				s_fdf;

typedef	struct
{
    int		i;
    int		j;
    int		k;
	int		l;
}				s_var;

void    parser(char *);
void	checker(char ***);
void	read_file(char *, s_fdf *);
int		map_hieght(char *);
int		map_width(char *);
void	get_values(s_point *, char *);
int		hexTodec(char *hexVal);
#endif