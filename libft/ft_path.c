/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:03:37 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/08 14:03:46 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char            *ft_path(char *dir, char *file)
{
    int         i;
    char        *tmp;
    char        *ret;

    tmp = NULL;
    i = ft_strlen(dir);
    tmp = (dir[i - 1] == '/') ? ft_strdup(dir) : ft_strjoin(dir, "/");
    ret = ft_strjoin(tmp, file);
    free(tmp);
    return (ret);
}
