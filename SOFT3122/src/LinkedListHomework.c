/*
 * Lecture4LinkedList.c
 *
 *  Created on: 23 Mar 2022
 *      Author: cmshalom
 */
#include <stdio.h>
#include <malloc.h>

struct element {
	int value;
	struct element *next;
};

struct element *head = NULL;
struct element *tail = NULL;

void append(int i) {
    struct element *new_element = malloc(sizeof(struct element));
    new_element->value  = i;
    new_element->next = NULL;

    if (tail != NULL) {
        tail->next = new_element;
    } else {
    	head = new_element;
    }

    tail = new_element;
}

void print_all() {
	struct element *p = head;
	while (p != NULL) {
		printf("%d\n", p->value);
		p = p->next;
	}
}

int find(int i) {
	struct element *p = head;
	while (p != NULL) {
		if (p->value == i) return 1;
		p = p->next;
	}
	return 0;
}
