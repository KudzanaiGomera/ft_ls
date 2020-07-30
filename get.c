/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:26:03 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/10 23:56:31 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char                *getSmallFileName(struct fileList *pFileList)
{
    char            *rtn = NULL;

    if (!pFileList)
    {
        return NULL;
    }

    if (!pFileList->pFileName)
    {
        return NULL;
    }

    rtn = ft_strrchr(pFileList->pFileName, '/'); 

    return *rtn == '\0' ? pFileList->pFileName : (rtn + 1);
}
char                *getOwnerName(struct stat *fileAttr)
{
       struct passwd *ownerName;
    

    if (!fileAttr)
    {
        return NULL;
    }
    
    ownerName = getpwuid(fileAttr->st_uid);
    if (ownerName)
        {
            return ownerName->pw_name;
        }
    return ft_itoa(fileAttr->st_uid);
}

char                *getOwnerGroup(struct stat *fileAttr)
{
        struct group  *ownerGroup;
            

    if (!fileAttr)
    {
        return NULL;
    }
    
    ownerGroup = getgrgid(fileAttr->st_gid);
     
    if (ownerGroup)
    {
        return ownerGroup->gr_name;
    }
    return ft_itoa(fileAttr->st_gid);
}

char                *getLastModification(struct stat *fileAttr)
{
    char            *rtn = NULL;
    if (!fileAttr)
    {
        return NULL;
    }

    rtn = ctime(&(fileAttr->st_mtime));

    if (rtn)
    {
        char *sec = ft_strrchr(rtn, ':');
        if (sec)
        {
            *sec = '\0';
        }
        rtn = ft_strchr(rtn, ' ');
    }

    return rtn;
}
int             getLinkCount(struct stat *fileAttr)
{
    if (!fileAttr)
    {
        return 0;
    }

    return fileAttr->st_nlink;
}
int             getFileSize(struct stat *fileAttr)
{
    if (!fileAttr)
    {
        return 0;
    }
    return fileAttr->st_size;
}
char *getPermissions(struct stat *fileAttr)
{
    char *tab;
    int mode;

    if (fileAttr)
    {
        mode = fileAttr->st_mode;
    }
    else
    {
        return NULL;
    }

    if (!(tab = malloc(sizeof(char) * 10)))
    {
        return NULL;
    }
    
    tab[0] = ((mode & S_IRUSR) != 0) ? 'r' : '-';
    tab[1] = ((mode & S_IWUSR) != 0) ? 'w' : '-';
    tab[2] = ((mode & S_IXUSR) != 0) ? 'x' : '-';
    tab[3] = ((mode & S_IRGRP) != 0) ? 'r' : '-';
    tab[4] = ((mode & S_IWGRP) != 0) ? 'w' : '-';
    tab[5] = ((mode & S_IXGRP) != 0) ? 'x' : '-';
    tab[6] = ((mode & S_IROTH) != 0) ? 'r' : '-';
    tab[7] = ((mode & S_IWOTH) != 0) ? 'w' : '-';
    tab[8] = ((mode & S_IXOTH) != 0) ? 'x' : '-';
    tab[9] = '\0';
    if (mode & S_ISUID)
        tab[2] = (mode & S_IXUSR) ? 's' : 'S'; 
    if (mode & S_ISGID)
        tab[5] = (mode & S_IXGRP ? 's' : 'S');
    
    return tab;
}
