/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:42:26 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/20 23:58:11 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, void *fdf1)
{
	t_fdf	*fdf;
	static t_var	offset;

	fdf = (t_fdf * )fdf1;
	ft_putstr("Key is =\n");
	ft_putnbr(key);
	ft_putstr("\n");
	if (key == 53)
		exit(0);
	if (key == 69)
		{
			fdf->zoom *= 2;
			mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		}
	if(key == 78)
	{
		if(fdf->zoom != 1)
			fdf->zoom /= 2;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	if (key == 123)
		{
			mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
			offset.x -= 10;
		}
	if (key == 124)
		{
			mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
			offset.x += 10;
		}
	if (key == 126)
		{
			mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
			offset.y -= 10;
		}
	if (key == 125)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		offset.y += 10;
	}
	draw_iso(fdf, offset);
	return 0;
}



void	get_values(t_point *map_line, char *line)
{
	char	**split;
	char	**sp;
	int		i;
	
	split = NULL;
	split = ft_strsplit(line, ' ');

	if (!split)
		ft_putendl("errrrrror");
	i = 0;
	while (split[i])
	{
		if (!ft_strchr(split[i], ','))
			{
				map_line[i].v = ft_atoi(split[i]);
				if (map_line[i].v == 0)
					map_line[i].color = WHITE;
				else
					map_line[i].color = PINK;
			}
		else
		{
			sp = ft_strsplit(split[i], ',');
			map_line[i].v = ft_atoi(sp[0]);
			map_line[i].color = hexTodec(sp[1] + 2);
			ft_bonus_freedoubledem(sp);
		}
		i++;
	}
	ft_bonus_freedoubledem(split);
}

void	read_file(char *file, t_fdf *fdf)
{
    int		fd;
	char	*line;
	int		i;
	
	map_dimensions(file, &fdf->width, &fdf->hieght);
	fdf->map_table = (t_point**)malloc(sizeof(t_point*) * (fdf->hieght + 1));
	i = 0;
	while (i <= fdf->hieght)
		fdf->map_table[i++] = (t_point*)malloc(sizeof(t_point) * (fdf->width + 1));
	i = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	while (i < fdf->hieght && get_next_line(fd, &line))
	{
		get_values(fdf->map_table[i], line);
		ft_strdel(&line);
		i++;
	}
	fdf->map_table[i] = NULL;
	fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 2000, 2000, "FDF");
	fdf->zoom = 1;
	//home();
	mlx_key_hook(fdf->win_ptr, deal_key, (void *)fdf);
	ft_putstr("\n");
	mlx_loop(fdf->mlx_ptr);
	close (fd);	
}