/*
 * TreeHomeworkMain.c
 *
 *  Created on: 3 May 2022
 *      Author: cmshalom
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>

#include "tree.h"

static TREE * trees[] = {NULL, NULL, NULL, NULL, NULL};
static int max_trees = sizeof(trees)/sizeof(TREE *);

#define LINE_LEN 80
static char input_line[LINE_LEN];
static int tree_number;
static int value;

static int read_parameters(char *s) {
	int result = sscanf(s, "%d %d", &tree_number, &value);
	assert(tree_number < max_trees);
	return result;
}

static void create() {
    printf("CREATING TREE NUMBER %d WITH VALUE: %d\n",
    		tree_number, value);
    trees[tree_number] = tree_create(value);
}

static void add() {
    printf("ADDING %d TO TREE NUMBER %d\n", value, tree_number);
    tree_add(trees[tree_number], value);
}

static void find() {
    printf("LOOKING FOR %d IN TREE NUMBER %d\n", value, tree_number);
    TREE * t = tree_find(trees[tree_number], value);
    if (t) {
    	int v = tree_value(t);
    	if (v != value) {
        	printf("PROBLEM IN FIND: FOUND %d INSTEAD OF %d \n", v, value);
    	} else {
    		printf("FOUND\n");
    	}
    } else {
		printf("NOT FOUND\n");
    }
}

static void delete() {
    printf("DELETING TREE NUMBER %d\n", tree_number);
    tree_delete(trees[tree_number]);
}

static void inorder() {
    printf("INORDER TRAVERSAL OF TREE NUMBER %d\n", tree_number);
    tree_print_inorder(trees[tree_number]);
}

static void postorder() {
    printf("POSTORDER TRAVERSAL OF TREE NUMBER %d\n", tree_number);
    tree_print_postorder(trees[tree_number]);
}

static int total_allocations = 0;
static int blocks_allocated = 0;

void *my_malloc(int size) {
	assert(size);
	total_allocations++;
	blocks_allocated++;
	return malloc(size);
}

void my_free(void *p) {
	assert(p);
	blocks_allocated--;
	return free(p);
}

void print_dynamic_memory_statistics() {
	printf("TOTAL ALLOCATIONS: %d \n", total_allocations);
	if (blocks_allocated) {
		printf("MEMORY LEAK ?: %d BLOCKS STILL ALLOCATED\n", blocks_allocated);
	}
}

int main() {
	while(fgets(input_line, LINE_LEN, stdin)) {
		int number_of_parameters = read_parameters(input_line+1);
		switch (toupper(input_line[0])) {
		case 'C':
			assert(number_of_parameters == 2);
			create();
			break;
		case 'A':
			assert(number_of_parameters == 2);
			add();
			break;
		case 'F':
			assert(number_of_parameters == 2);
			find();
			break;
		case 'D':
			assert(number_of_parameters == 1);
			delete();
			break;
		case 'I':
			assert(number_of_parameters == 1);
			inorder();
			break;
		case 'P':
			assert(number_of_parameters == 1);
			postorder();
			break;
		}
		printf("\n");
	}
	print_dynamic_memory_statistics();
	return 0;
}
