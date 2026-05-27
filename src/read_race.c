#include <stdio.h>

#include "read_race.h"
#include "clear.h"

Race read_race(void) {

	unsigned int choice;

	while (1) {
		CLEAR_SCREEN();
		printf("Insert your race:\n\n[1]White\n[2]Black\n[3]Mixed\n[4]Asian\n[5]Native American\n\nChoose one option: ");

		if (scanf("%u", &choice) == 1 && (choice > 0 && choice < 6)) {
			while (getchar() != '\n');
			CLEAR_SCREEN();
			return (Race)(choice - 1);
		}

		printf("Invalid option! Type only the options available.\n");
		while (getchar() != '\n');
	}
}
