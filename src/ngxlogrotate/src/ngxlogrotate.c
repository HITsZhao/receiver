
/*
 * Copyright (C) zhao
 */

#include<ngxlogrotate.h>

static int nlr_get_options(int argc, char* const*argv);
static u_char* nlr_cpylinen(u_char *dst, u_char *src, size_t n);

static int nlr_show_help;

int main(int argc, char** argv)
{
	nlr_fd_t fd;
	const u_char *p;
	int i = 0;
	const u_char *conf[CONF_ITEM_NUM] = {NULL, NULL, NULL};
	u_char *buf = malloc(MAX_FILE_SIZE);

	if(nlr_get_options(argc, argv) != NLR_OK)
		return 1;
	fd = nlr_open_file("nlr.conf", NLR_FILE_RDONLY, NLR_FILE_OPEN, 0);
	if(fd == NLR_INVALID_FILE){
		printf("open file nlr.conf failed\n");
		return 1;
	}
	
	memset(buf, 0, MAX_FILE_SIZE);
	ssize_t n = nlr_read_file(fd, buf, MAX_FILE_SIZE);
	printf("read %d bytes from file\n", (int)n);
	
	p = buf;
	conf[i] = p;
	while(*p && i < CONF_ITEM_NUM){
		if(*p++ == '\n'){
			printf("conf %d is %s", i, conf[i]);
			conf[++i] = p;
		}
	}
		
	nlr_cpylinen(NULL, NULL, 0);
	free(buf);
	nlr_close_file(fd);	
	return NLR_OK;
}

static int
nlr_get_options(int argc, char* const*argv)
{
	u_char *p;
	int		i;
	
	for(i = 1; i < argc; i++){
		p = (u_char*)argv[i];
		
		if(*p++ != '-'){
			printf("invalid option: \"%s\"", argv[i]);
			return NLR_ERROR;
		}

		while(*p){
			switch(*p++){
				case '?':
				case 'h':
					nlr_show_help = 1;
					break;
				default:
					printf("invalid option: \"%c\"", *(p - 1));
					return NLR_ERROR;
			}
		}
		continue;
	}
	return NLR_OK;
}

static u_char* 
nlr_cpylinen(u_char *dst, u_char *src, size_t n)
{
	if(n == 0){
		return dst;
	}
	
	while(--n){
		*dst = *src;
		if(*dst == '\n'){
			return dst;
		}
		dst++;
		src++;
	}
	return dst;
}

