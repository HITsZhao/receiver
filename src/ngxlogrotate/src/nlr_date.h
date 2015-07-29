
/*
 * Copyright (C) zhao
 */

#ifndef _NLR_DATE_H_INCLUDED_
#define _NLR_DATE_H_INCLUDED_

#define NLR_DATE_FORMATE "%Y-%m-%d"
#define NLR_DATE_EXMPLE "1990-01-01"

typedef struct tm nlr_tm_t;

int nlr_now(nlr_tm_t *tm);

size_t nlr_strftime(char *s, const nlr_tm_t *tm);

char *nlr_strptime(const char *s, struct tm *tm);


#endif /*_NLR_DATE_H_INCLUDED_*/
