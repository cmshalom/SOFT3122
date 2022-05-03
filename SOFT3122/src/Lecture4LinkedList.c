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

void append1(int i) {
    struct element *new_element = malloc(sizeof(struct element));
    (*new_element).value  = i;
    (*new_element).next = NULL;

    (*tail).next = new_element;

    tail = new_element;
}

void append2(int i) {
    struct element *new_element = malloc(sizeof(struct element));
    (*new_element).value  = i;
    (*new_element).next = NULL;

    if (tail != NULL) {
        (*tail).next = new_element;
    } else {
    	head = new_element;
    }

    tail = new_element;
}

void append3(int i) {
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

int main() {
	append3(5);
	append3(7);
	print_all();
	return 0;
}
