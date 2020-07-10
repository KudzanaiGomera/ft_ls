/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:55:39 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/09 15:29:17 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void                arr_free(char *chr, char **arr, int i)
{
    int             j;

    j = 0;
    if (arr != NULL)
    {
        while (j < i)
        {
            free(arr[j]);
            j++;
        }
        free(arr);
    }
    if (chr != NULL)
        free(chr);
}
