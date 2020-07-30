/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:10:13 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/11 00:02:24 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int             main(int argc, char **argv)
{
    int         options;
    int         rtn = EXIT_SUCCESS;

    options = processParams(argc, argv);

    if (options >= 0)
    {
        /*
         *      allocate memory for file
         *              */
        pFileListHead = allocNode(NULL, _DEFAULT_DIR);

        if (pFileListHead)
        {
            pFileListHead->isDir = 1;

            rtn = processDirectory(options, pFileListHead);

            if (rtn >= 0)
            {
                rtn = displayResults(options, pFileListHead);
            }
            rtn = houseCleaning(pFileListHead);
        }
        else
        {
            rtn = EXIT_FAILURE;
            logError("main memory alloc");
        }
    }
    else
    {
        printUsage();
        rtn = EXIT_FAILURE;
    }
    return rtn;
}

int             handleSort(int params, struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;

    if (params & _T_SORTED_OPTION)
    {
        bubbleSort(pFileList, _1_TIME_SORT);
    }
    else if (params & _R_REVERSE_OPTION)
    {
        bubbleSort(pFileList, _0_NAME_SORT);
    }

    return rtn;
}

struct fileList *allocNode(char *parentPath, char *name)
{
    struct fileList *pNode;
    int         len;

    pNode = malloc(sizeof(struct fileList));
    if (pNode)
    {
        pNode->isDir = 0;
        pNode->total = 0;
        pNode->pDirent = NULL;
        pNode->pNext = NULL;
        pNode->pPrev = NULL;
        pNode->pChild = NULL;
        pNode->pFileAttr = NULL;

        if (parentPath)
        {
            len = ft_strlen(parentPath) + ft_strlen(name) + 2;    
        }
        else
        {
            len = ft_strlen(name) + 1;
        }

        pNode->pFileName = malloc(sizeof(char) * len);
        if (!pNode->pFileName)
        {
            free(pNode);
            pNode = NULL;
            logError("allocNode memory alloc 1");
        }
        else
        {
            if (parentPath)
            {
                ft_strcpy(pNode->pFileName, parentPath);
                ft_strcat(pNode->pFileName, "/");
                ft_strcat(pNode->pFileName, name);
            }
            else
            {
                ft_strcpy(pNode->pFileName, name);
            }
        }
    }
    else
    {
        logError("allocNode memory alloc 2");
    }
    return pNode;
}

int             houseCleaning(struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;
    struct fileList *pCurrent;
    struct fileList *temp;

    pCurrent = pFileList;

    while (pCurrent)
    {
        if (pCurrent->pFileAttr)
        {
            free(pCurrent->pFileAttr);
        }
        free(pCurrent->pFileName);

        if (pCurrent->pChild)
        {
            rtn = houseCleaning(pCurrent->pChild);
        }
        temp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(temp);
    }
    return rtn;
}

void           logError(char *desc)
{
    printf("ERROR: %s\n", desc);
    ft_putstr(desc);
    ft_putchar('\n');
}
void printUsage()
{
    ft_putstr("ft_ls: illegal option -- ");
    ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
    exit(0);
}
