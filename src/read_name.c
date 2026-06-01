#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "read_name.h"
#include "clear.h"

char* read_name(const char *label)
{
	CLEAR_SCREEN();
	if (label == NULL) return NULL;

	char buffer[31];
	
	while (1) {
		printf("\nType the %s:\n... ", label);
		//Receives the string in a buffer
		fgets(buffer, sizeof(buffer), stdin);

		//Limits the string's size
		if (buffer[strcspn(buffer, "\n")] != '\n')
		{
			printf("\nThe %s is too long! Try it again.\n", label);
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			continue;
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		break;
	}

	//Remove spaces that came before the word
	char *p_start = buffer;
	while(*p_start == ' ' || *p_start == '\t'){
		p_start++;
	}
	if (p_start != buffer) {
		memmove(buffer, p_start, strlen(p_start) + 1);
	}
	
	//ToUpper All
	for (size_t i = 0; i < strlen(buffer); i++)
	{
		buffer[i] = toupper(buffer[i]);
	}

	//Allocates the string and send it back
	char *name_ptr = (char *) malloc(strlen(buffer) + 1);
	if (name_ptr != NULL) {
		strcpy(name_ptr, buffer);
	}
	CLEAR_SCREEN();

	return name_ptr;
}
