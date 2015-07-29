
/*
 * Copyright (C) zhao
 */

#ifndef _NLR_H_INCLUDED_
#define _NLR_H_INCLUDED_

#define _GNU_SOURCE
#include<stdint.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<linux/limits.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
#include<nlr_file.h>
#include<nlr_date.h>

#define NLR_OK 0
#define NLR_ERROR -1

#define CONF_ITEM_NUM 3
#define MAX_FILE_SIZE (CONF_ITEM_NUM * PATH_MAX)

#define VG_LOG_DEFAULT_PATH "/home/sftp/NBP_AAS/vg_upload"
#define CLI_LOG_DEFAULT_PATH "/home/sftp/NBP_AAS/client_upload"

#endif /*_NLR_H_INCLUDED_*/
