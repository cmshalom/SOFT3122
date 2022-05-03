/*
 * Lecture4.c
 *
 *  Created on: 23 Mar 2022
 *      Author: cmshalom
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char system[] = "SYSTEM";
char prog[] = "PROGRAMMING";

void concat1() {
	char result[19];

	strcpy(result, system);
	strcat(result, " ");
	strcat(result, prog);

	printf("%s\n", result);

}

void concat2() {
	char result[13]; // THIS ONE WILL CRASH SINCE IT OVERRIDES MEMORY

	strcpy(result, system);
	strcat(result, " ");
	strcat(result, prog);

	printf("%s\n", result);

}

void concat3() {
	int len = strlen(system) + 1 + strlen(prog) + 1;
	char result[len];

	strcpy(result, system);
	strcat(result, " ");
	strcat(result, prog);

	printf("%s\n", result);

}

/*
 * Returns an automatically allocated array
 * Gives a compile time warning and does not work
 */
char *concat4() {
	int len = strlen(system) + 1 + strlen(prog) + 1;
	char result[len];

	strcpy(result, system);
	strcat(result, " ");
	strcat(result, prog);

	return result;
}

/*
 * Dynamically allocates the result and returns it
 */
char *concat5() {
	int len = strlen(system) + 1 + strlen(prog) + 1;
	char *result = malloc(len);

	strcpy(result, system);
	strcat(result, " ");
	strcat(result, prog);

	return result;
}

int main() {
	char *result = concat5();
	printf("%s\n", result);
	free(result);
}
