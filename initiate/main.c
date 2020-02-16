/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:56:33 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/07 21:24:20 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
    void*   mlx_ptr;
    void*   mlx_ptr_win;
    mlx_ptr = mlx_init();
    mlx_ptr_win = mlx_new_window(mlx_ptr, 500, 500, "mehdi");
    mlx_loop(mlx_ptr);
}
