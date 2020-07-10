/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgomera <kgomera@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:21:07 by kgomera           #+#    #+#             */
/*   Updated: 2020/07/10 23:25:25 by kgomera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "./libft/libft.h"
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define _L_LISTING_OPTION   (1 << 0)
#define _A_HIDDEN_OPTION    (1 << 1)
#define _R_REVERSE_OPTION   (1 << 2)
#define _T_SORTED_OPTION    (1 << 3)
#define _R_RECURSIVE_OPTION (1 << 4)

#define _L_LISTING_PARAM    'l'
#define _A_HIDDEN_PARAM 'a'
#define _R_REVERSE_PARAM    'r'
#define _T_SORTED_PARAM 't'
#define _R_RECURSIVE_PARAM  'R'

#define _0_NAME_SORT    0
#define _1_TIME_SORT    1
#define _REVERSE_SORT   1

#define _DEFAULT_DIR    "."
#define _ERROR      -1
#define ARGS            9

struct fileList
{
    char *pFileName;
    int isDir;
    long total;
    struct dirent *pDirent;
    struct stat *pFileAttr;
    struct stat b;
    struct fileList *pPrev;
    struct fileList *pNext;
    struct fileList *pChild;
};

struct fileList *pFileListHead;

int processParams(int argc, char **argv);
int handleSort(int params, struct fileList *pFileList);
int processDirectory(int params, struct fileList *pFileList);
int processFiles(int params, DIR *pDir, struct fileList *pFileList);
struct fileList *allocNode(char *parentPath, char *name);
int processFile(int params, struct fileList *pFileList);
int processRecursive(int params, struct fileList *pFileList, char *simpleName);
int displayResults(int options, struct fileList *fileList);
int displayList(struct fileList *pFileList);
int displayRecursive(int options, struct fileList *pFileList);
int displayChildren(int options, struct fileList *pFileList);
int houseCleaning(struct fileList *fileList);
char *getSmallFileName(struct fileList *pFileList);
char *getOwnerName(struct stat *fileAttr);
char *getOwnerGroup(struct stat *fileAttr);
char *getLastModification(struct stat *fileAttr);
int getLinkCount(struct stat *fileAttr);
int getFileSize(struct stat *fileAttr);
char *getPermissions(struct stat *fileAttr);
void logError(char *desc);
void printUsage();
void bubbleSort(struct fileList *start, int which);
void swap(struct fileList *a, struct fileList *b, struct fileList *head);
int compareNode(struct fileList *a, struct fileList *b, int which);

#endif
