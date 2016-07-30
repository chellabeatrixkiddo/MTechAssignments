// Include Libraries:
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Macro Definitions:
#define MAXLEN 30
#define MAXFILES 10
#define VFSOPEN 0
#define VFSCLOSE 1

// Error Code Macro Definitions:
#define ERROR_CODE_1 1
#define ERROR_CODE_2 2
#define ERROR_CODE_3 3
#define ERROR_CODE_4 4
#define ERROR_CODE_5 5
#define ERROR_CODE_6 6
#define ERROR_CODE_7 7

// Error Message Macro Definitions:
#define ERROR_MSG_1 "VFS Could Not Be Created\n"
#define ERROR_MSG_2 "VFS Could Not Be Loaded\n"
#define ERROR_MSG_3 "File Could Not Be Saved Onto VFS\n"
#define ERROR_MSG_4 "File Could Not Be Read from VFS\n"
#define ERROR_MSG_5 "VFS Could Not Be Unloaded\n"
#define ERROR_MSG_6 "VFS Is Not Loaded\n"
#define ERROR_MSG_7 "External File To Be Saved, Cannot Be Opened\n"

// Structure Declarations:
#ifndef VFS_INFO_H
#define VFS_INFO_H
struct vfs_info {
    char name_of_vfs[MAXLEN];
    int num_files;
};
#endif

#ifndef VFS_FILE_INFO_H
#define VFS_FILE_INFO_H
struct vfs_file_info {
    char name_of_file[MAXLEN];
    int offset;
    int file_size;
};
#endif

#ifndef VFS_HEADER_INFO_H
#define VFS_HEADER_INFO_H
struct vfs_header_info {
    struct vfs_info vfs_h_info;
    struct vfs_file_info vfs_files[MAXFILES];
};
#endif

#ifndef VFS_H
#define VFS_H
struct vfs {
    struct vfs_header_info header;
    FILE* vfs_fp;
    int vfs_status;
} ;
#endif

/*// Global Variable Declarations:
extern struct vfs_info vfs041_info;
extern struct vfs_header_info vfs041_header_info;
extern struct vfs vfs041;*/

// Function Prototypes:
int vfs_create(char* name_with_path); // Creates a VFS
int vfs_load(char* name_with_path); // Loads the VFS
int vfs_save(char* saved_file_name, char* ext_file_name_with_path); // Save file to VFS
int vfs_extract(char* saved_file_name, char* ext_file_name_with_path); // Read file from VFS
int vfs_unload(); // Unload the VFS

