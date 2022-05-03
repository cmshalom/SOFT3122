#include <stdio.h>

extern void append(int i);
extern void print_all();
extern int find(int i); // returns zero if i is not in the list, and non-zero otherwise

#define FOUND "FOUND"
#define NOT_FOUND "NOT FOUND"

int main() {
	append(5);
	append(7);
	append(4);

	print_all();

	char *str = find(3) ? FOUND : NOT_FOUND;
    printf("%s\n", str);
	str = find(7) ? FOUND : NOT_FOUND;
    printf("%s\n", str);

}
