/*
 * rawio.c
 *
 *      Author: cmshalom
 */
#include <stdio.h>
#include <string.h>
#include <memory.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define BUF_SIZE 100

int main() {
	int fd = open("input", O_RDWR);
    printf("fd=%d\n", fd);
    if (fd < 0) return 1;

    char buf[BUF_SIZE];
    memset(buf, 'X', BUF_SIZE);
    int result = read(fd, buf, BUF_SIZE);
    printf("read returned %d\n", result);
    if (result < 0) return 2;

    if(lseek(fd, 0L, SEEK_SET) < 0) {
        printf("error in lseek\n");
        return 4;
    }

    memcpy(buf, "ABC", 3);
    result = write(fd, buf, result);
    printf("write returned %d\n", result);
    if (result < 0) return 3;

    result = close(fd);
    if (result < 0) return 5;

	return 0;
}
