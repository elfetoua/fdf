/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:18:51 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/16 00:03:47 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		usage()
{
	ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}

int				main(int ac, char **av)
{
    s_fdf	*fdf;
    
    fdf = (s_fdf*)malloc(sizeof(s_fdf)); // remember to free
	
    (ac != 2) ? usage() : read_file(av[1], fdf);
	return (0);
}