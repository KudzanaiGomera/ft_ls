/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:34:02 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/08 12:39:39 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_count_words(const char *s, char c)
{
    int words;

    words = 0;
    while (*s == c)
        s++;
    while (*s)
    {
        while (*s && *s != c)
            s++;
        while (*s == c)
            s++;
        words++;
    }
    return (words);
}
