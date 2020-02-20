/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:42:26 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/20 20:24:50 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, void *fdf1)
{
	t_fdf *fdf;
	fdf = (t_fdf * )fdf1;
	ft_putstr("Key is =\n");
	ft_putnbr(key);
	ft_putstr("\n");
	draw_parallel(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_parallel(fdf);
	return 0;
}

int		hexTodec(char *hexVal) 
{
    int len;
    int base; 
    int dec_val;
	int	i;
	
	len = ft_strlen(hexVal);
	base = 1;
	dec_val = 0;
	i = len - 1;
    while (i >= 0)
    {
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            dec_val += (hexVal[i] - 48) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <='F')
        {
            dec_val += (hexVal[i] - 55) * base; 
            base = base * 16;
        }
		i--;
    }
    return dec_val;
}

void		map_dimensions(char *file, int *clmn_nbr, int *line_nbr)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	*line_nbr = 0;
	line = NULL;
	ret = 0;
	ret = get_next_line(fd, &line);
	if (ret > 0)
		(*line_nbr)++;
	*clmn_nbr = ft_bonus_countwords(line, ' ');
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		++(*line_nbr);
		ft_strdel(&line);
	}
	close (fd);
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
				map_line[i].color = 0;
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
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "mehdi");
	fdf->zoom = 25;
	home();
	mlx_key_hook(fdf->win_ptr, deal_key, (void *)fdf);
	ft_putstr("\n");
	mlx_loop(fdf->mlx_ptr);
	close (fd);	
}