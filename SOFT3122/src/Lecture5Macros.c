/*
 * Lecture5Macros.c
 *
 *  Created on: 30 Mar 2022
 *      Author: cmshalom
 */

#include <stdio.h>

#define SIZE1 100
#define SIZE2 200

int main() {
	int arr1[SIZE1];
	for (int i=0; i<SIZE1; i++) {
		printf("%d\n", arr1[i]);
	}
	int arr2[SIZE2];
	for (int i=0; i<SIZE2; i++) {
		printf("%d\n", arr2[i]);
	}

}
