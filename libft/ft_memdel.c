/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:06:06 by kgomera           #+#    #+#             */
/*   Updated: 2019/06/14 09:46:27 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void			ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
