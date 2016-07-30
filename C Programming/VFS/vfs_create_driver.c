#include "vfs.h"

// cmd line: executable_name vfs_name_with_path

int main(int argc, char* argv[]) {
    int create_status = 0;
    printf("Demo of a Virtual File System: VFS\n");
    
    // Creating the VFS:
    printf("Creating VFS.....\n");
    create_status = vfs_create(argv[1]);
    if(create_status == ERROR_CODE_1)
    	printf(ERROR_MSG_1);
    else
    	printf("VFS Created\n"); 
    
    return 0;
}