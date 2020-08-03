/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:23:51 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/10 21:27:55 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void                bubbleSort(struct fileList *pFileList, int which)
{
    int             sorted;
    struct fileList *ptr1;
    struct fileList *lptr = NULL;

    /*
     *      Checking for empty list 
     *           */
    if (pFileList == NULL)
        return;

    sorted = 0;
    while (!sorted)
    {
        ptr1 = pFileList->pChild;
        sorted = 1;

        while (ptr1)
        {
            lptr = ptr1->pNext;
            if (!lptr)
            {
                break;
            }
            if (compareNode(ptr1, ptr1->pNext, which) > 0)
            {
                swap(ptr1, ptr1->pNext, pFileList);
                lptr = ptr1;
                sorted = 0;
            }
            ptr1 = lptr;
        }
    }
}

char *toUpperCase (char *str)
{
    char *rtn = malloc(ft_strlen(str));
    size_t cnt;
    
    cnt = 0;
    if (!rtn)
    {
        return rtn;
    }

    while(cnt < ft_strlen(str))
    {
        rtn[cnt] = str[cnt];

        if (str[cnt] > 96 && str[cnt] < 123)
        {
            rtn[cnt] = str[cnt] - 32;
        }
        cnt++;
    }
    return rtn;
}
int             compareNode(struct fileList *a, struct fileList *b, int which)
{
    int         rtn = 0;
    char *firstStr, *secStr;

    if (!b && which == 0)
    {
        return 1;
    }
    else if (!b)
    {
        return -1;
    }
    if (which == _0_NAME_SORT)
    {
        firstStr = toUpperCase(a->pFileName);
        secStr = toUpperCase(b->pFileName);

        rtn = strcmp(firstStr, secStr);
        if (firstStr)
        {
            free(firstStr);
        }
        if (secStr)
        {
            free(secStr);
        }

        rtn = rtn * -1;
    }
    else if (which == _1_TIME_SORT)    
        /*
         *     time modified
         *         */
    {
        rtn = difftime (a->pFileAttr->st_mtime, b->pFileAttr->st_mtime);
    }
    else
    {
        firstStr = toUpperCase(a->pFileName);
        secStr = toUpperCase(b->pFileName);

        rtn = strcmp(firstStr, secStr);
        if (firstStr)
        {
            free(firstStr);
        }
        if (secStr)
        {
            free(secStr);
        }
    }
    
    return rtn;
}

void                swap(struct fileList *a, struct fileList *b, struct fileList *head)
{
    struct fileList *tmp;

    a->pNext = b->pNext;
    b->pNext = a;

    tmp = a->pPrev;
    a->pPrev = b;
    if (tmp == head)
    {
        tmp->pChild = b;
    }
    else
    {
        tmp->pNext = b;
    }
    b->pPrev = tmp;
    if (a->pNext)
    {
        a->pNext->pPrev = a;
    }
}