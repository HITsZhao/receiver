
/*
 * Copyright (C) zhao
 */

#include<ngxlogrotate.h>

int nlr_now(nlr_tm_t *tm)
{
	time_t t = time(NULL);
	tm = localtime(&t);
	if(tm == NULL)
		return -1;	
	return 0;
}

size_t nlr_strftime(char *s, const nlr_tm_t *tm)
{
	return strftime(s, sizeof(NLR_DATE_EXMPLE), NLR_DATE_FORMATE, tm);
}

char *nlr_strptime(const char *s, struct tm *tm)
{
	
	return strptime(s, NLR_DATE_FORMATE, tm);
}
