
/*
 * Copyright (C) zhao
 */

#include<ngxlogrotate.h>

ssize_t 
nlr_read_file(nlr_fd_t fd, u_char *buf, size_t size)
{
	ssize_t  n;
	n = read(fd, buf, size);
	if (n == -1) {
        printf("read() failed");
        return NLR_ERROR;
	}
	return n;
}

int 
is_file_exists(const u_char *file)
{
	if (file == NULL)
		return NLR_ERROR;
	DIR *dir = opendir((const char*)file);
	if ( dir != NULL){
		closedir(dir);
		return NLR_OK;
	}
	return NLR_ERROR;
}

