
/*
 * Copyright (C) zhao
 */

#include<ngxlogrotate.h>

static int nlr_get_options(int argc, char* const*argv);
static int nlr_conf_parse(const char* filename);
static const u_char* nlr_cpylinen(u_char *dst, const u_char *src, size_t n);

static int nlr_show_help;
static u_char vg_conf[PATH_MAX];
static u_char cli_conf[PATH_MAX];
static u_char days_conf[PATH_MAX];

int main(int argc, char** argv)
{
	nlr_get_options(argc, argv);
	if(nlr_conf_parse("nlr.conf") == NLR_ERROR){
		return 1;
	}
	
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

static const u_char* 
nlr_cpylinen(u_char *dst, const u_char *src, size_t n)
{
	if(n == 0){
		return dst;
	}
	
	while(--n){
		if(*src == '\n'){
			return ++src;
		}else{
			*dst = *src;
		}
		dst++;
		src++;
	}
	return ++src;
}
static int 
nlr_conf_parse(const char* filename)
{
	
	nlr_fd_t fd;
	const u_char *p;
	int i = 0;
	u_char *conf[CONF_ITEM_NUM] = {vg_conf, cli_conf, days_conf};
	u_char *buf = malloc(MAX_FILE_SIZE);

	fd = nlr_open_file(filename, NLR_FILE_RDONLY, NLR_FILE_OPEN, 0);
	if(fd == NLR_INVALID_FILE){
		printf("open file %s failed\n", filename);
		return NLR_ERROR;
	}
	
	memset(buf, 0, MAX_FILE_SIZE);
	ssize_t n = nlr_read_file(fd, buf, MAX_FILE_SIZE);
	printf("read %d bytes from file\n", (int)n);
	
	p = buf;
	while(*p && i < CONF_ITEM_NUM){
		p = nlr_cpylinen(conf[i++], p, PATH_MAX);
	}
	printf("%s\n", vg_conf);
	printf("%s\n", cli_conf);
	printf("%s\n", days_conf);

	if(is_file_exists(vg_conf) != NLR_OK){
		printf("%s doesn't exists\n", vg_conf);
		return NLR_ERROR;
	}	
	
	if(is_file_exists(cli_conf) != NLR_OK){
		printf("%s doesn't exists\n", cli_conf);
		return NLR_ERROR;
	}
		
	nlr_cpylinen(NULL, NULL, 0);
	free(buf);
	nlr_close_file(fd);	
	return NLR_OK;
}
