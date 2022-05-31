
// Implements a stack of non-negative integers
#define STACK_SIZE 100

int stack[STACK_SIZE];
int *top = stack - 1;

int is_empty() {
    return top < stack;
}

int is_full() {
    return top >= stack + STACK_SIZE - 1;
}

int push(int i) {
	if (is_full()) return -1;
	if (i < 0) return -1;
    top++;
    *top = i;
    return 0;
}

int pop() {
	if (is_empty()) return -1;
	top--;
	return top[1];
	// return *(top+1) is also OK
}

