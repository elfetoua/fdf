/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:39:41 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/20 22:40:16 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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