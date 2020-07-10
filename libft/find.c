/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:28:49 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/09 15:36:20 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int                 find(char *str, char *str2)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    while (str[i] != '\0' || str[j] != '\0')
    {
        while (str[i] == '.')
            i++;
        while (str2[j] == '.')
            j++;
        if (ft_tolower(str[i]) != ft_tolower(str2[j]))
        {
            if (ft_tolower(str[i]) > ft_tolower(str2[j]))
                return (str[i]);
            else
                return (0);
        }
        if (str[i] != '\0')
            i++;
        if (str[j] != '\0')
            j++;
    }
    return (0);
}
