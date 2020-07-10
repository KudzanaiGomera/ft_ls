/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:55:33 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/08 13:55:49 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void            ft_lstaddend(t_list **alst, t_list *new)
{
    if ((*alst)->next != NULL)
        ft_lstaddend(&(*alst)->next, new);
    else
    {
        (*alst)->next = new;
    }
}
