#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "is_numeric_string.h"

int is_numeric_string(const char *str) {
	
	if (strlen(str) == 0) return 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit((unsigned char)str[i])) return 0;
	}
	return 1;
}
