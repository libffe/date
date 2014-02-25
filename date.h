/*
 * GIT - The information manager from hell
 *
 * Copyright (C) Linus Torvalds, 2005
 */

#ifndef DATE_H
#define DATE_H

#include <stddef.h>
#include <sys/time.h>

enum date_mode {
	DATE_NORMAL = 0,
	DATE_RELATIVE,
	DATE_SHORT,
	DATE_LOCAL,
	DATE_ISO8601,
	DATE_RFC2822,
	DATE_RAW
};

const char *show_date(unsigned long time, int timezone, enum date_mode mode);
int parse_date(const char *date, char *buf, int bufsize);
int parse_date_basic(const char *date, unsigned long *timestamp, int *offset);
int parse_expiry_date(const char *date, unsigned long *timestamp);
void datestamp(char *buf, int bufsize);
#define approxidate(s) approxidate_careful((s), NULL)
unsigned long approxidate_careful(const char *, int *);
unsigned long approxidate_relative(const char *date, const struct timeval *now);
enum date_mode parse_date_format(const char *format);

#endif
