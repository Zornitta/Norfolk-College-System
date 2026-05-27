#include <stdio.h>
#include <time.h>

#include "clear.h"
#include "date.h"

Date read_birth_date(void) {
	Date d;

	time_t t = time(NULL);
	struct tm tm_info = *localtime(&t);
	unsigned int current_year = tm_info.tm_year + 1900;

	while (1) {
		CLEAR_SCREEN();
		printf("Insert your birthdate (DD/MM/AAAA): ");

		if (scanf("%u/%u/%u", &d.day, &d.month, &d.year) != 3) {
			printf("Invalid format! Use the pattern DD/MM/AAAA\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');

		if (d.month < 1 || d.month > 12) {
			printf("\nInvalid month! Type a value between 1 and 12.\n");
			continue;
		}
		if (d.day < 1 || d.day > 31) {
			printf("\nInvalid day! Type a value between 1 and 31.\n");
			continue;
		}
		if (d.year < 1900 || d.year > current_year) {
			printf("\nInvalid year! Type a year between 1900 and %u.\n", current_year);
			continue;
		}

		if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30) {
			printf("\nThis month has only 30 days!\n");
			continue;
		}

		if (d.month == 2) {
			unsigned int is_leap = (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0);
			if (is_leap && d.day > 29) {
				printf("Febuary is leap year and has only 29 days!\n");
				continue;
			} else if (!is_leap && d.day > 28) {
				printf("Febuary has at most 28 years!\n");
				continue;
			} 
		}
		break;
	}

	CLEAR_SCREEN();
	return d;	
}
