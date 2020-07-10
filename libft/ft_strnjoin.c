/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:06:23 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/08 14:09:19 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_strnjoin(char const *s1, char const *s2, size_t len,\
        char const *s3)
{
    char    *ret;

    ret = NULL;
    if (s1 && s2)
    {
        if ((ret = (char*)malloc(sizeof(char)*ft_strlen(s1) + len + ft_strlen(s3) + 1)) == NULL)
            return (NULL);
        ft_strcpy(ret, s1);
        ft_strncat(ret, s2, len);
        ft_strcat(ret, s3);
    }
    return (ret);
}
