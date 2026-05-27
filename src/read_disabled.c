#include <stdio.h>

#include "read_disabled.h"
#include "clear.h"

char read_disabled(void) {
	
	char answer;

	while (1) {
		CLEAR_SCREEN();
		printf("Do you have any disability? [Y/N]\n\n");

		if (scanf("%c", &answer) == 1 && (answer == 'Y' || answer == 'N')) {
			while (getchar() != '\n');
			CLEAR_SCREEN();
			return answer;
		}

		printf("Invalid option! Type Y or N.");
		while (getchar() != '\n');
	}
} 
