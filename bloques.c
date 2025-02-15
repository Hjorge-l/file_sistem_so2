#include <stdio.h>
#include <fcntl.h>

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

int main(){
    printf("hola mundo soy un file sistem");
    return 0;
}
