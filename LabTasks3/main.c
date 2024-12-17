#include <stdio.h>
#include <stdlib.h>
// You may want to create function prototypes in my_header.h file.
#include "my_header.h"

void stdin_clear() {
	while (getchar() != '\n');
}

void all_print(char* name, char* surname, int year, double score) {
	printf("Name: %s\nSurname: %s\nYear: %d\nScore: %.2lf\n",
		name, surname, year, score);
}

int input_string(char* str, unsigned int str_length) {
	char format[64];
	int result = 0;

	sprintf_s(format, sizeof(format), "%%%ds", str_length - 1);
	result = scanf(format, str);
	return result;
}

int input_string_safely(char* str, unsigned int str_length) {
	char format[64];
	int result = 0;

	sprintf_s(format, sizeof(format), "%%%ds", str_length - 1);
	result = scanf_s(format, str, str_length);
	return result;
}

int input_int(int* p_number) {
	int result = 0;
	result = scanf("%d", p_number);
	return result;
}

int input_int_safely(int* p_number) {
	int result = 0;
	result = scanf_s("%d", p_number);
	return result;
}

int input_double(double* p_number) {
	int result = 0;
	result = scanf("%lf", p_number);
	return result;
}

int input_double_safely(double* p_number) {
	int result = 0;
	result = scanf_s("%lf", p_number);
	return result;
}

int main() {

	char name[128];
	char surname[128];
	int year;
	double score;
#ifdef SAFE_MODE
	printf("Using SAFE_MODE\n");
	printf("Name: \n");
	input_string_safely(name, (unsigned int)sizeof(name));
	stdin_clear();
	printf("Surname: \n");
	input_string_safely(surname, sizeof(surname));
	stdin_clear();
	printf("Year of birth: \n");
	input_int_safely(&year);
	stdin_clear();
	printf("Score: \n");
	input_double_safely(&score);
	stdin_clear();
#else 
	printf("Not Using SAFE_MODE\n");
	printf("Name: \n");
	input_string(name, (unsigned int)sizeof(name));
	stdin_clear();
	printf("Surname: \n");
	input_string(surname, (unsigned int)sizeof(surname));
	stdin_clear();
	printf("Year of birth: \n");
	input_int(&year);
	stdin_clear();
	printf("Score: \n");
	input_double(&score);
	stdin_clear();
#endif
	all_print(name, surname, year, score);
}

#undef SAFE_MODE