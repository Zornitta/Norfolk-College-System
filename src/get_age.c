#include <stdio.h>
#include <time.h>

#include "get_age.h"
#include "date.h"

unsigned int get_age(Date *d) {

	time_t current_time;

	time(&current_time);

	struct tm *local_data = localtime(&current_time);

	unsigned int current_day = local_data->tm_mday;
	unsigned int current_month = local_data->tm_mon + 1;
	unsigned int current_year = local_data->tm_year + 1900;

	unsigned int age = current_year - d->year;

	if (current_month < d->month || (current_month == d->month && current_day < d->day)) {	
		age--;
	}

	return age;
}
