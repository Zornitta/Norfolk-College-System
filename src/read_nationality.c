#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "countries.h"
#include "clear.h"

void read_nationality(char *dest) {
	char input[4];

	while (1) {
		CLEAR_SCREEN();
		printf("Type your nationality alpha-3 (3 letters - ex: USA, BRA, GBR)\n\n... ");

		if (scanf("%3s", input) == 1) {
			while (getchar() != '\n');

			for (int i = 0; i < 3; i++) {
				input[i] = toupper(input[i]);
			}

			int found = 0;
			for (size_t i = 0; i < TOTAL_COUNTRIES; i++) {
				if (strcmp(input, VALID_COUNTRIES[i]) == 0) {
					found = 1;
					break;
				}	
			}

			if (found) {
				strcpy(dest, input);
				CLEAR_SCREEN();
				return;
			}
		}
		else {
			while (getchar() != '\n');	
		}

		printf("Invalid ISO code! Try it again.\n");
	}
}
