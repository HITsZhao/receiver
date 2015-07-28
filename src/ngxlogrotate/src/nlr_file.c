
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
	if (access((const char *)file, F_OK) == 0)
		return NLR_OK;
	return NLR_ERROR;
}

