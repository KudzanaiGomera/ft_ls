/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:42:30 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/08 12:42:54 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int         ft_intlen(int n)
{
    if (n == -2147483648)
        return (11);
    if (n < 0)
        return (1 + ft_intlen(-n));
    if (n < 10)
        return (1);
    else
        return (1 + ft_intlen(n / 10));
}
