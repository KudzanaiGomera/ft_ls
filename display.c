/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:59:58 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/10 23:24:46 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int             displayResults(int options, struct fileList *pFileList)
{
    int         rtn;
    struct      fileList *pCurrent;
    
    rtn = EXIT_SUCCESS;
    pCurrent = pFileList;

    rtn = handleSort(options, pFileList);

    if (options & _R_RECURSIVE_OPTION)
    {
        displayRecursive(options, pCurrent);
    }
    else
    {
        pCurrent = pFileList->pChild;
        while (pCurrent)
        {
            if (options & _L_LISTING_OPTION)
            {
                displayList(pCurrent);
            }
            else
            {
                ft_putstr(getSmallFileName(pCurrent));
                ft_putchar('\t');
                ft_putchar('\n');
            }

            pCurrent = pCurrent->pNext;
        }
    }
    return rtn;
}
int             displayList(struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;
    char        *pFilePerms;

    pFilePerms = getPermissions(pFileList->pFileAttr);
    ft_putstr(pFilePerms);
    ft_putchar('\t');
    ft_putnbr(getLinkCount(pFileList->pFileAttr));
    ft_putchar('\t');
    ft_putstr(getOwnerName(pFileList->pFileAttr));
    ft_putchar('\t');
    ft_putstr(getOwnerGroup(pFileList->pFileAttr));
    ft_putchar('\t');
    ft_putnbr(getFileSize(pFileList->pFileAttr));
    ft_putchar('\t');
    ft_putstr(getLastModification(pFileList->pFileAttr));
    ft_putchar('\t');
    ft_putstr(getSmallFileName(pFileList));
    ft_putchar('\n');

    if (pFilePerms)
    {
        free(pFilePerms);
    }
    return rtn;
}
int             displayRecursive(int options, struct fileList *pFileList)
{
    int         rtn;
    struct fileList *pCurrent;
    struct fileList *pCurrentChild;
    
    rtn = EXIT_SUCCESS;
    pCurrent = pFileList;

    if (pCurrent)
    {
        if (pCurrent->isDir)
        {
            ft_putstr(pCurrent->pFileName);
            ft_putchar('\n');
            if (options & _L_LISTING_OPTION)
            {
                ft_putstr("Total ");
                ft_putnbr(pCurrent->total);
                ft_putchar('\n');
            }
            rtn = displayChildren(options, pCurrent->pChild);
            ft_putstr("\n");
            ft_putchar('\n');
            pCurrentChild = pCurrent->pChild;

            while (pCurrentChild)
            {
                if (pCurrentChild->isDir)
                {
                    char *smallName = getSmallFileName(pCurrentChild);
                    if (strcmp(smallName, ".") && strcmp(smallName, ".."))
                    {
                        rtn = displayResults(options, pCurrentChild);
                    }
                }
                pCurrentChild = pCurrentChild->pNext;
            }
        }
        else
        {
            ft_putstr(getSmallFileName(pCurrent));
            ft_putchar('\t');
        }

        pCurrent = pCurrent->pNext;
    }

    return rtn;
}

int             displayChildren(int options, struct fileList *pFileList)
{
    int         rtn;
    struct      fileList *pCurrent;
    
    rtn = EXIT_SUCCESS;
    pCurrent = pFileList;

    while (pCurrent)
    {
        if (options & _L_LISTING_OPTION)
        {
            displayList(pCurrent);
        }
        else
        {
            ft_putstr(getSmallFileName(pCurrent));
            ft_putchar('\t');
        }

        pCurrent = pCurrent->pNext;
    }

    return rtn;
}
