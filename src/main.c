/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:18:51 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/18 11:21:22 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		usage(void)
{
	ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)malloc(sizeof(t_fdf)); // remember to free
	(ac != 2) ? usage() : read_file(av[1], fdf);
	return (0);
}
