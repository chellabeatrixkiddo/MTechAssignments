#include "vfs.h"

// cmd line: executable_name vfs_name_with_path, file_name_to_use, ext_file_to_read_and_save, ext_file_to_extract_into

int main(int argc, char* argv[]) {
	int load_status = 0, save_status = 0, extract_status = 0, unload_status = 0;
    printf("Demo of a Virtual File System: VFS\n");
    
    printf("1. Save a File to the VFS\n");
    // Loading the VFS:
    printf("Loading VFS.....\n");
    load_status = vfs_load(argv[1]);
    if(load_status == ERROR_CODE_2) {
    	printf(ERROR_MSG_2);
    }
    else
    	printf("VFS Loaded\n");
    		
	// Saving File to VFS:
    printf("Saving the file in VFS.....\n");
    save_status = vfs_save(argv[2], argv[3]);
    if(save_status == ERROR_CODE_3 || save_status == ERROR_CODE_6 || save_status == ERROR_CODE_7) {
    	(save_status == 3 || save_status == 6)?((save_status == 3)?printf(ERROR_MSG_3):printf(ERROR_MSG_6)):printf(ERROR_MSG_7);
	}
	else
    	printf("File Saved. VFS Updated\n");
    		
    // Unloading the VFS:
    printf("Unloading VFS.....\n");
    unload_status = vfs_unload();
    if(unload_status == ERROR_CODE_5) {
    	printf(ERROR_MSG_5);
    }
    else
    	printf("VFS Unloaded\n");
    			
    		
    printf("2. Read a File from the VFS\n");
    // Loading the VFS:
    printf("Loading VFS.....\n");
    load_status = vfs_load(argv[1]);
    if(load_status == ERROR_CODE_2) {
    	printf(ERROR_MSG_2);
    }
    else
    	printf("VFS Loaded\n");
    		
    // Reading File from VFS
    printf("Reading the file from VFS.....\n");
    extract_status = vfs_extract(argv[2],argv[4]);
    if(extract_status == ERROR_CODE_4 || extract_status == ERROR_CODE_6 || extract_status == ERROR_CODE_7) {
    	(extract_status == 4 || extract_status == 6)?((extract_status == 4)?printf(ERROR_MSG_4):printf(ERROR_MSG_6)):printf(ERROR_MSG_7);
    
    }
    else
    	printf("File Read.\n");
    		
    // Unloading the VFS:
    printf("Unloading VFS.....\n");
    unload_status = vfs_unload();
    if(unload_status == ERROR_CODE_5) {
    	printf(ERROR_MSG_5);
    }
    else
    	printf("VFS Unloaded\n");
    			
    printf("VFS Operations Done!\n");
    
    return 0;
}