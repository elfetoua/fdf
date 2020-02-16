/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:00:11 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/16 00:10:11 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

void	parser(char *file)
{
    int		fd;
	int		line_nbr;
	//int		clmn_nbr;
	char	*line;
	char	***val_pos;

	fd = open(file, O_RDONLY);
	line_nbr = 0;
	while (get_next_line(fd, &line))
		{
			line_nbr++;
			free(line);
		}
	ft_putnbr(line_nbr);
	if (line_nbr == 0)
		ft_putendl("No Data");
	close(fd);
	fd = open(file, O_RDONLY);
	line_nbr = 0;
	val_pos = (char ***)malloc(sizeof(char**) * (line_nbr + 1));
	while (get_next_line(fd, &line))
	{
		val_pos[line_nbr] = ft_strsplit(line, ' ');
		line_nbr++;
		free(line);
	}
	val_pos[line_nbr] = NULL;
	checker (val_pos);
	close(fd);
}