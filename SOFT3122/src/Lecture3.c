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

void print_sizes() {
	int i = 7;
	int *p = NULL;
	char *q = NULL;

	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(short)=%ld\n", sizeof(short));
	printf("sizeof(int *)=%ld\n", sizeof(int*));
	printf("sizeof(char *)=%ld\n", sizeof(char*));
	printf("sizeof(i)=%ld\n", sizeof(i));
	printf("sizeof(p)=%ld\n", sizeof(p));
	printf("sizeof(q)=%ld\n", sizeof(q));
}

int* pointer_referencing() {
	int i = 7;
	int *p = NULL;
	char *q = NULL;

	printf("i=%d\n", i);
	p = &i;
	*p = 0x41424344;
	printf("i=%d\n", i);
	q = (char*) p;
	printf("*q=%c\n", *q);
	return p;
}

void pointer_arithmetic() {
	int i;
	int *p = &i;
	char *q = (char *) p;

	printf("p=%lx\n", (long) p);
	printf("q=%lx\n", (long) q);
	p++;
	q++;
	printf("p=%lx\n", (long) p);
	printf("q=%lx\n", (long) q);
}

void pointer_arithmetic2() {
	int i = 0x41424344;
	int *p = &i;
	char *q = (char *) p;

	for (int j=0; j<sizeof(i); j++) {
		printf("%c\n", *q);
		q++;
	}
    printf("\n");
	q = (char *) p;
	for (int j=0; j<sizeof(i); j++) {
		printf("%c\n", *(q+j));
	}
    printf("\n");
}

void pointer_arithmetic3() {
	int i = 0x41424344;
	int *p = &i;
	char *q = (char *) p;

	for (int j=0; j<sizeof(i); j++) {
		printf("%c\n", q[j]);
	}
    printf("\n");

}

int main(void) {
	print_sizes();
	pointer_referencing();

	pointer_arithmetic();
	pointer_arithmetic2();
	pointer_arithmetic3();

}
