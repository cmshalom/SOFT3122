/*
 ============================================================================
 Name        : SOFT3122.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char p[] = "SYSTEMS PROGRAMMING";


void print_ascii_codes() {
	for (int i=0; i<sizeof(p); i++) {
		printf("%d\n", p[i]);
	}
}

void print_integers() {
	int *q = (int *) p;
	for (int i=0; i<4; i++) {
		printf("%d\n", q[i]);
	}
}


int main(void) {
    print_ascii_codes();
    print_integers();
}
