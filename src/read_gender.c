#include <stdio.h>

#include "read_gender.h"
#include "clear.h"

Gender read_gender(void) {
	
	unsigned int choice;

	while (1) {
		CLEAR_SCREEN();
		printf("Insert your gender:\n\n[1]Male\n[2]Female\n\nChoose one option: ");

		if (scanf("%u", &choice) == 1 && (choice == 1 || choice == 2)) {
			while (getchar() != '\n');
			
			CLEAR_SCREEN();
			return (Gender)(choice - 1);
		}

		printf("Invalid option! Type only valid answers(1 or 2).\n");
		while (getchar() != '\n');
	}
}
