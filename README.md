# ft_ls
reproducing ft_ls

# How to run it

$ git clone the repo

$ make  // to compile

$ ./ft_ls -l // or -r || -a || -R

$ make fclean // to clean objects and executable file

$make clean //for *.o files only

info about ft_ls


/*
   Data Type: DIR
   The DIR data type represents a directory stream.
   You shouldn’t ever allocate objects of the struct dirent
   or DIR data types, since the directory access functions
   do that for you. Instead, you refer to these objects
   using the pointers returned by the following functions.
   */

/*
   On Linux, the dirent structure is defined as follows:
   struct dirent {
   ino_t          d_ino;       // inode number
   off_t          d_off;       // offset to the next dirent
   unsigned short d_reclen;    // length of this record
   unsigned char  d_type;      // type of file; not supported
   by all file system types
   char           d_name[256]; //filename
   };
   */

// struct stat mystat;

/*
   The opendir() function opens a directory stream corresponding to the
   directory name, and returns a pointer to the directory stream.  The
   stream is positioned at the first entry in the directory.
   DIR *opendir(const char *name);
   */


/*
   The readdir() function returns a pointer to a dirent
   structure representing the next directory entry in the
   directory stream pointed to by dirp. It returns NULL on
   reaching the end of the directory stream or if an error occurred.

   BASICALLY CHECKS THE FILES THAT ARE IN THE CURRENT DIRECTORY
   struct dirent *readdir(DIR *dirp);
   */

### To Do

- fix display to case sensetive, eg -l and -r
- fix d permissions in -l
- error handling if user pass dir that does not exist and as well as file
- make flags work if the user pass dir after -l flag
