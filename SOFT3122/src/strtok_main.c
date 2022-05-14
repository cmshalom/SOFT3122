/*
 * try.c
 *
 *  Created on: 11 May 2022
 *      Author: cmshalom
 */

#include<stdio.h>
#include<string.h>

extern char *my_strtok(char *s, const char *delim);

#define BUFLEN 100

int main() {
	char *delimiters = " \n\t";
	char buf[BUFLEN];

	while(fgets(buf, BUFLEN, stdin)) {
		char *word = my_strtok(buf, delimiters);
		while(word) {
			printf("%s --- %d\n", word, (int) strlen(word));
			word = my_strtok(NULL, delimiters);
		}
	}
	return 0;
}
