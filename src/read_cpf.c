#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "read_cpf.h"
#include "is_numeric_string.h"
#include "clear.h"

char* read_cpf(void) {

	char buffer[32];

	while (1) {

		CLEAR_SCREEN();	
		printf("\nType your CPF\n\n... ");
		
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			continue;		
		}

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] != '\n') {
			printf("\nTyped CPF is too long! Try it agan (Don't use dots and dashes).\n");

			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (!is_numeric_string(buffer)) {
			printf("\nInvalid characters! Type ONLY numbers (no letters, dots or dashes).\n");
			continue;
		}
		
		if (strlen(buffer) != 11) {
			printf("A valid CPF must have exactly 11 digits. Try it again.\n");
			continue;
		}
		
		char *cpf_ptr = malloc(strlen(buffer) + 1);
		if (cpf_ptr != NULL) {
			strcpy(cpf_ptr, buffer);
			CLEAR_SCREEN();
			return cpf_ptr;
		}
	}
}
