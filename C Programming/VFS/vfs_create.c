#include "vfs.h"

struct vfs_info vfs041_info;
struct vfs_header_info vfs041_header_info;

int vfs_create(char* name_with_path) {
    int i = 0;
    char* file_name;
    file_name = (char*)malloc(sizeof(char)*MAXLEN);
    
    // create a vfs file
    FILE* fp;
    fp = fopen(name_with_path, "wb+");
    if(fp == NULL)
    	return ERROR_CODE_1;
    
    // get the file name from the name_with_path
    for(i = strlen(name_with_path)-1; i >= 0; i--) {
    	if(name_with_path[i] == '/')
    		break;
    }
    strcpy(file_name, &(name_with_path[i+1]));
    
    // initialize vfs information
    
    strcpy(vfs041_info.name_of_vfs, file_name);
    vfs041_info.num_files = 0;
    
    vfs041_header_info.vfs_h_info = vfs041_info;
    
    // save header at the beginning of the file
    fwrite(&vfs041_header_info, sizeof(struct vfs_header_info), 1, fp);
    
    // close the vfs file
    fclose(fp);
    
    return 0;
}