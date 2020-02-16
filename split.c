/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:46:49 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/15 18:51:12 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char                    **ft_strsplit(char const *s, char c);

int main()
{
    char a[] = "this is a simple	example    t check  what is goi  ing to hapen";
    char **spl;

    int i = 0;
    spl = ft_strsplit(a, ' ');
    while(spl[i])
    {
        printf("%s\n", spl[i]);
        i++;
    }
}