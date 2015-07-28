
/*
 * Copyright (C) zhao
 */

#ifndef _NLR_FILE_H_INCLUDED_
#define _NLR_FILE_H_INCLUDED_

typedef int nlr_fd_t;
#define NLR_INVALID_FILE -1

ssize_t nlr_read_file(nlr_fd_t fd, u_char *buf, size_t size);
int is_file_exists(const u_char *file);

#define nlr_open_file(name, mode, create, access)   open((const char *) name, mode|create, access)

#define NLR_FILE_RDONLY          O_RDONLY
#define NLR_FILE_WRONLY          O_WRONLY
#define NLR_FILE_RDWR            O_RDWR
#define NLR_FILE_CREATE_OR_OPEN  O_CREAT
#define NLR_FILE_OPEN            0
#define NLR_FILE_TRUNCATE        (O_CREAT|O_TRUNC)
#define NLR_FILE_APPEND          (O_WRONLY|O_APPEND)
#define NLR_FILE_NONBLOCK        O_NONBLOCK

#define nlr_read_fd              read


#define nlr_close_file           close


#define nlr_delete_file(name)    unlink((const char *) name)


#endif /*_NLR_FILE_H_INCLUDED_*/
