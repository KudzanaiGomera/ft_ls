/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:33:03 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/10 21:31:15 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int             processParams(int argc, char **argv, char **startDir)
{
    int         rtn = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            for (int j = 1; argv[i][j]; j++)
            {
                if (argv[i][j] == _L_LISTING_PARAM)
                {
                    rtn = rtn | _L_LISTING_OPTION;
                }
                else if (argv[i][j] == _A_HIDDEN_PARAM)
                {
                    rtn = rtn | _A_HIDDEN_OPTION;
                }
                else if (argv[i][j] == _R_REVERSE_PARAM)
                {
                    rtn = rtn | _R_REVERSE_OPTION;
                }
                else if (argv[i][j] == _T_SORTED_PARAM)
                {
                    rtn = rtn | _T_SORTED_OPTION;
                }
                else if (argv[i][j] == _R_RECURSIVE_PARAM)
                {
                    rtn = rtn | _R_RECURSIVE_OPTION;
                }
                else
                {
                    rtn = -1;
                    break;
                }
            }
        }
        else
        {
            *startDir = argv[i];
        }
        if (rtn < 0)
        {
            break;
        }
    }

    return rtn;
}

int             processDirectory(int params, struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;
    DIR         *pDir;

    pDir = opendir(pFileList->pFileName);
    if (!pDir)
    {
        logError("No such file or directory \n");
        rtn = _ERROR;
    }
    else
    {
        rtn = processFiles(params, pDir, pFileList);

        closedir(pDir);
    }

    return rtn;
}



int             processFiles(int params, DIR *pDir, struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;
    struct fileList *pNewFileList;
    struct fileList *pCurrent;
    struct dirent *pDirent;

    pCurrent = pFileList;
    /*process directory entries*/
    while ((pDirent = readdir(pDir)) != NULL)
    {
        /*check if we are displaying hidden files*/
        if (!(params & _A_HIDDEN_OPTION))
        {
            if (pDirent->d_name[0] == '.')
            {
                continue;
            }
        }
        pNewFileList = allocNode(pFileList->pFileName, pDirent->d_name);

        if (!pNewFileList)
        {
            return _ERROR;
        }
        if (!pFileList->pChild)
        {
            pFileList->pChild = pNewFileList;
            pNewFileList->pPrev = pFileList;
        }
        else
        {
            pCurrent->pNext = pNewFileList;
            pNewFileList->pPrev = pCurrent;
        }
        pNewFileList->pDirent = pDirent;

        rtn = processFile(params, pNewFileList);

        if (S_ISDIR(pNewFileList->pFileAttr->st_mode))
        {
            pNewFileList->isDir = 1;
            rtn = processRecursive(params, pNewFileList, pDirent->d_name);
        }
        pCurrent = pNewFileList;
    }

    return rtn;
}

int             processFile(int params, struct fileList *pFileList)
{
    int         rtn = EXIT_SUCCESS;
    params = 0;

    pFileList->pFileAttr = malloc(sizeof(struct stat));
    if (!pFileList->pFileAttr)
    {
        logError("processFile memory alloc");
        ft_isdigit(params);
        rtn = _ERROR;
    }
    else
    {
        rtn = stat(pFileList->pFileName, pFileList->pFileAttr);
    }
    return rtn;
}

int             processRecursive(int params, struct fileList *pFileList, char *simpleName)
{
    int         rtn = EXIT_SUCCESS;

    if ((params & _R_RECURSIVE_OPTION))
    {
        if (ft_strcmp(".", simpleName) && ft_strcmp("..", simpleName))
        {
            rtn = processDirectory(params, pFileList);
        }
    }

    return rtn;
}
