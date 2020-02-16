/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:42:26 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/16 01:56:17 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

// Function to convert hexadecimal to decimal
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
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
            // incrementing base by power
            base = base * 16;
        }
  
        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base; 
            // incrementing base by power
            base = base*16;
        }
		i--;
    }
    return dec_val;
}

int		map_hieght(char *file)
{
	int		fd;
	char	*line;
	int		line_nbr;

	fd = open(file, O_RDONLY);
	line_nbr = 0;
	while (get_next_line(fd, &line))
	{
		line_nbr++;
		free(line);
	}
	close (fd);
	return (line_nbr);
}

int		map_width(char *file)
{
	int		fd;
	char	*line;
	int		clmn_nbr;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	clmn_nbr = ft_bonus_countwords(line, ' ');
	free(line);
	close(fd);
	return (clmn_nbr);
}

void	get_values(s_point *map_line, char *line)
{
	char	**split;
	char	**sp;
	int		i;
	char	*hex;
	
	split = ft_strsplit(line, ' ');
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
			hex = ft_strdup(sp[1] + 2);
			ft_putendl(hex);
			map_line[i].color = hexTodec(hex);
			free(hex);
			ft_bonus_freedoubledem(sp);
		}
		free(split[i]);
		i++;
	}
	free(split);
}

void	read_file(char *file, s_fdf *fdf)
{
    int		fd;
	char	*line;
	int		i,j;
	
	fdf->hieght = map_hieght(file);
	fdf->width = map_width(file); // == the 1st line width
	fdf->map_table = (s_point**)malloc(sizeof(s_point*) * (fdf->width + 1));
	i = 0;
	while (i <= fdf->hieght)
		fdf->map_table[i++] = (s_point*)malloc(sizeof(s_point) * (fdf->width));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		get_values(fdf->map_table[i], line);
		free(line);
		i++;
	}
	fdf->map_table[i] = NULL;
	i = 0;
	while(fdf->map_table[i])
	{
		j = 0;
		while(j < fdf->width)
		{
			ft_putendl("value is: ");
			ft_putnbr(fdf->map_table[i][j].v);
			ft_putstr("\n");
			ft_putendl("color is: ");
			ft_putnbr(fdf->map_table[i][j].color);
			ft_putstr("\n");
			j++;
		}
		i++;
	}
	close (fd);	
}