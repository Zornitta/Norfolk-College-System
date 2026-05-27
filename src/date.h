#ifndef DATE_H
#define DATE_H


typedef struct {
	unsigned int day;
	unsigned int month;
	unsigned int year; 
} Date;

Date read_birth_date(void);

#endif
