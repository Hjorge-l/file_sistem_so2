#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCKSIZE 512
#define FALSE 0
#define TRUE 1
#define ERROR -1

int bmount(const char *camino) {
    int fd = open(camino, O_RDWR, 0666);
    
    if (fd == ERROR) {
        perror("bmount");
        return ERROR;
    }
    return fd;
}

int bumount(int fd) {
    if (close(fd) == ERROR) {
        perror("bumount");
        return ERROR;
    }
    return 0;
}

int bwrite(unsigned int nbloque, const void *buf) {
    return 0;
}

int main(int argc, char *argv[]){
    printf("Abriendo el fichero\n");
    bmount(argv[1]);
    printf("Cerrando el fichero %s\n", argv[1]);
    return 0;
}
