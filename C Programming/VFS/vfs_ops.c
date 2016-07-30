#include "vfs.h"

struct vfs_info vfs041_info;
struct vfs_header_info vfs041_header_info;
struct vfs vfs041;

int vfs_load(char* name_with_path) {

    // open the vfs file 
    FILE* fp = fopen(name_with_path, "rb+");
    if(fp == NULL)
    	return ERROR_CODE_2;
    
    // load the header info struct
    fread(&vfs041_header_info, sizeof(struct vfs_header_info), 1, fp);
    
    // initialize struct vfs
    vfs041.header = vfs041_header_info;
    vfs041.vfs_fp = fp;
    vfs041.vfs_status = VFSOPEN;
    return 0;
}

int vfs_save(char* saved_file_name, char* ext_file_name_with_path) {
    char* buffer;
    int file_length;
    int save_at_offset;
    
    // precondition: vfs is loaded
    if(vfs041.vfs_status == VFSCLOSE)
        return ERROR_CODE_6;
    
    // open the external file to be saved
    FILE* ext_fp = fopen(ext_file_name_with_path, "rt");
    if(ext_fp == NULL)
    	return ERROR_CODE_7;
    
    // calculate the offset where the file needs to be saved
    fseek(vfs041.vfs_fp, 0, SEEK_END);
    save_at_offset = ftell(vfs041.vfs_fp);
    
    // initialize vfs_file_info structure
    struct vfs_file_info file1;
    strcpy(file1.name_of_file, saved_file_name);
    file1.offset = save_at_offset;
    
    // calculate the size of the external file
    fseek(ext_fp, 0, SEEK_END);
    file_length = ftell(ext_fp);
    rewind(ext_fp);
    file1.file_size = file_length;
    
    vfs041_header_info.vfs_files[vfs041_info.num_files] = file1;
    
    // allocate buffer of the size of the file
    buffer = (char*) malloc(sizeof(char)*file_length);
    
    // read external file contents
    if((fread(buffer, sizeof(char), file_length, ext_fp)) != file_length)
    	return ERROR_CODE_3;
    
    // write external file contents at the offset location
    if((fwrite(buffer, sizeof(char), file_length, vfs041.vfs_fp)) != file_length)
    	return ERROR_CODE_3;
    
    // increment num_files counter
    vfs041_info.num_files = vfs041_info.num_files + 1;
    
    return 0;
}

int vfs_extract(char* saved_file_name, char* ext_file_name_with_path) {
    int extract_from_offset;
    int no_of_bytes_to_read;
    char* buffer;
    
    // precondition: vfs is loaded
    if(vfs041.vfs_status == VFSCLOSE)
    	return ERROR_CODE_6;
    
    // iterate on vfs_file_info array
    for(int i = 0; i < vfs041_info.num_files; i++) {
        if((strcmp(vfs041_header_info.vfs_files[i].name_of_file, saved_file_name)) == 0) {
            extract_from_offset = vfs041_header_info.vfs_files[i].offset;
            no_of_bytes_to_read = vfs041_header_info.vfs_files[i].file_size;
            break;
        }
    }
    
    // locate the offset
    fseek(vfs041.vfs_fp, extract_from_offset, SEEK_SET);
    
    // allocate buffer of the size of the file
    buffer = (char*) malloc(sizeof(char)*no_of_bytes_to_read);
    
    // read the bytes to be read
    if((fread(buffer, sizeof(char), no_of_bytes_to_read, vfs041.vfs_fp)) != no_of_bytes_to_read)
    	return ERROR_CODE_4;
    
    // open external file which is empty
    FILE* ext_fp = fopen(ext_file_name_with_path, "wt");
    if(ext_fp == NULL)
    	return ERROR_CODE_7;
    
    // save the bytes to the external file
    if((fwrite(buffer, sizeof(char), no_of_bytes_to_read, ext_fp)) != no_of_bytes_to_read)
    	return ERROR_CODE_4;
    
    // close external file
    fclose(ext_fp);
    
    return 0;
}

int vfs_unload() {
    // save header info into the vfs file
    rewind(vfs041.vfs_fp);
    if((fwrite(&vfs041_header_info, sizeof(struct vfs_header_info), 1, vfs041.vfs_fp)) != 1)
    	return ERROR_CODE_5;
    
    // close the vfs file
    fclose(vfs041.vfs_fp);
    
    // update the struct vfs
    vfs041.vfs_fp = NULL;
    vfs041.vfs_status = VFSCLOSE;
    return 0;
}