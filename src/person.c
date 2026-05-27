#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "person.h"
#include "date.h"
#include "read_name.h"
#include "read_birthdate.h"
#include "read_gender.h"
#include "read_race.h"
#include "read_civil_status.h"
#include "read_nationality.h"
#include "read_disabled.h"
#include "read_cpf.h"

Person create_person(void)
{
	Person p;

	p.name = read_name("Nome");
	p.surname = read_name("Sobrenome");
	p.birthDate = read_birth_date();
	p.gender = read_gender();
	p.race = read_race();
	p.civil_status = read_civil_status();
	read_nationality(p.nationality);
	p.isDisabled = read_disabled();
	
	p.cpf = read_cpf();

	return p;
}

const char* get_gender_name(Gender g) {
	switch(g) {
		case MALE: 		return "Male";
		case FEMALE: 		return "Female";
		default: 		return "Unknown";
	}
}

const char* get_race_name(Race r) {
	switch(r) {
		case White:		return "White";
		case Black:		return "Black";
		case Mixed:		return "Mixed";
		case Asian:		return "Asian";
		case Native_American	return "Native American";
		default:		return "Unknown";
	}
}

const char* get_civil_status_name(Civil_Status s) {
	switch(s) {
		case Single:		return "Single";
		case Married:		return "Married";
		case Separated		return "Separated";
		case Widowed:		return "Widowed";
		case Divorced:		return "Divorced";
		case Stable_Union:	return "Stable_Union";
		default: 		return "Unknown";
	}
}
