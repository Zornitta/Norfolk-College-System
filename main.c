#include <stdio.h>
#include <stdlib.h>

#include "clear.h"
#include "person.h"
#include "date.h"
#include "get_age.h"

int main(void) {

	//Declarações
	int option = 0;
	Person *database = NULL;
	unsigned total_people = 0;

	while (1)
	{	
		CLEAR_SCREEN();
		printf("---------------------------------------------\n");
		printf("--- WELCOME TO THE NORFOLK COLLEGE SYSTEM ---\n");
		printf("---------------------------------------------\n");
		printf("1. Login\n");
		printf("2. Register\n\n");
		printf("0. Close\n\n\n");
		printf("Insert the option: ");

		if (scanf("%d", &option) != 1) {
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');

		switch (option) {
		
			case 1: {
			CLEAR_SCREEN();
			printf("\n- Login\n\n");
			getchar();
			break;
			}
			case 2: {
			int register_option;
			int valid_choice = 0;

			do {
				CLEAR_SCREEN();
				printf("\n-Register\n");
				printf("1. Student\n");
				printf("2. Teacher\n");
				printf("3. Staff\n\n");
				printf("0. Return to Home\n");
				printf("\nInsert the option: ");

				if (scanf("%d", &register_option) != 1) {
					while (getchar() != '\n');
					printf("\nInvalid option! Press Enter...");
					getchar();
					continue;
				}
				while (getchar() != '\n');

				CLEAR_SCREEN();
				switch (register_option) {
					
					case 1: {
					printf("-- Student Register ---\n\n");
					Person p = create_person();	
					total_people++;

					printf("\nName: %s", p.name);
					printf("\nSurname: %s", p.surname);					
					printf("\nAge: %u", get_age(&p.birthDate));
					printf("\nGender: %s", get_gender_name(p.gender));
					printf("\nRace: %s", get_race_name(p.race));
					printf("\nCivil Status: %s", get_civil_status_name(p.civil_status));
					printf("\nNationality: %s", p.nationality);
					printf("\nIs Disabled: %c", p.isDisabled);
					printf("\nCPF: %s", p.cpf);
					printf("\n\nTotal People: %u", total_people);

					getchar();
					valid_choice = 1;
					break;
					}
					case 2: {
					printf("--- Teacher Register ---\n");
					getchar();
					valid_choice = 1;
					break;
					}
					case 3: {
					printf("-- Staff Register ---\n");
					getchar();
					valid_choice = 1;
					break;
					}
					case 0: {
					valid_choice = 1;
					break;	
					}
					default: {
					printf("Invalid Option!\n\nPress Enter to try again...");
					getchar();
					break;	
					}
				}
			} while (!valid_choice);
			
			break;
			}

			case 0:
			exit(0);
			break;

			default:
			printf("Invalid Option!\n\nPress Enter...");
			getchar();
			break;
		}
	}

	return 0;
}
