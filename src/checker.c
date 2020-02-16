/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:52:37 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/15 22:22:48 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	checker(char ***vp)
{
	register int		i;
	register int		j;
	register int		clmn;
	
	clmn = 0;
	while (vp[0][clmn])
		clmn++;
	ft_putstr("done\n");
	i = 0;
	while (vp[i] != NULL)
	{
		ft_putstr("good\n");
		j = 0;
		while (vp[i][j] != '\0')
			j++;
		ft_putstr("not here\n");
		if (j < clmn)
		{
			ft_putstr("Size Error\n");
			return ;
		}
		i++;
	}
}