#include <stdio.h>

#include "read_civil_status.h"
#include "clear.h"

Civil_Status read_civil_status(void) {
	
	unsigned int choice;

	while (1) {
		CLEAR_SCREEN();
		printf("Choose your civil status:\n\n[1]Single\n[2]Married\n[3]Separated\n[4]Widowed\n[5]Divorced\n[6]Stable Union\n\n");
		printf("Insert your option: ");

		if (scanf("%u", &choice) == 1 && (choice > 0 && choice < 7)) {
			while (getchar() != '\n');

			CLEAR_SCREEN();
			return (Civil_Status)(choice - 1);
		}

		printf("Invalid option! Type only available option.");
		while (getchar() != '\n');
	}
}
