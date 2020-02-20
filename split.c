/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:46:49 by elfetoua          #+#    #+#             */
/*   Updated: 2020/02/19 23:55:45 by elfetoua         ###   ########.fr       */
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
        if (hexVal[i] >= '0' && hexVal[i] <= '9')
        {
            dec_val += (hexVal[i] - 48) * base;
            // incrementing base by power
            base = base * 16;
        }
  
        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i] >= 'A' && hexVal[i] <='F')
        {
            dec_val += (hexVal[i] - 55) * base; 
            // incrementing base by power
            base = base * 16;
        }
		i--;
    }
    return dec_val;
}