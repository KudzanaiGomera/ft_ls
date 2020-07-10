/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:20:06 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/09 15:28:09 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char                **sort_char_tab(char *tab[], int size)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    while(i <= size - 1)
    {
        while (j < (size - i - 1))
        {
            if (find(tab[j], tab[j+1]) > 0)
                ft_swap(&tab[j], &tab[j + 1]);
            j++;
        }
        i++;
    }
    j = 0;
    return (tab);
}
