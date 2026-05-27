#ifndef PERSON_H
#define PERSON_H

#include "date.h"

typedef enum {
	MALE,
	FEMALE
} Gender;

typedef enum {
	White,
	Black,
	Mixed,
	Asian,
	Native_American	
} Race;

typedef enum {
	Single,
	Married,
	Separated,
	Widowed,
	Divorced,
	Stable_Union
} Civil_Status;

typedef struct{
	//Dados basicos
	unsigned int id;
	char *name;
	char *surname;
	Date birthDate;
	Gender gender;
	Race race;
	Civil_Status civil_status;
	char nationality[4];
	char isDisabled;
	//Dados Pessoais
	char *cpf;
	char *phone_number;
	char *email;
	//Endereço
	char number[10];
	char *street;
	char *neighborhood;
	char *city;
	char state[3];
	char cep[8];
} Person;

Person create_person(void);

//Getters
const char* get_gender_name(Gender g);
const char* get_race_name(Race r);
const char* get_civil_status_name(Civil_Status s);

#endif
