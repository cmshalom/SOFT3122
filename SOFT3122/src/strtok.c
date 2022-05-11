/*
 * try.c
 *
 *  Created on: 11 May 2022
 *      Author: cmshalom
 */

#include<stdio.h>
#include<string.h>

#define BUFLEN 100

int i;  // GLOBAL scope, PROGRAM lifetime

char *my_strtok(char *s, const char* delim) {
	int j;   // LOCAL scope, ACTIVATION lifetime
	static int k;   // LOCAL scope, PROGRAM lifetime
	return strtok(s, delim);
}

int main() {
	char *s = "ABC     XYZ\n\t   QWERTY";
	char *delimiters = " ";

	char buf[BUFLEN];

	strncpy(buf, s, BUFLEN);
	char *word;

	// word = strtok(s, delimiters); // This would get a memory fault
	                                 // because the first parameter is modified
	word = my_strtok(buf, delimiters);
	while(word) {
		printf("%s --- %d\n", word, (int) strlen(word));
		word = my_strtok(NULL, delimiters);
	}

	printf("Write someting and end with CR\n");
	gets(buf);
	word = my_strtok(buf, delimiters);
	while(word) {
		printf("%s --- %d\n", word, (int) strlen(word));
		word = my_strtok(NULL, delimiters);
	}

	return 0;
}
