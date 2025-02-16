#include "bloque.h"

static int descriptor = 0;

int bmount(const char *camino) {
    //Open virtual device
    int descriptor = open(camino, O_RDWR, 0666);
    
    if (descriptor == ERROR) {
        perror(RED "Error bmount");
        printf(RESET);
        return ERROR;
    }
    return descriptor;
}

int bumount() {
    if (close(descriptor) == ERROR) {
        perror(RED "Error bumount");
        printf(RESET);
        return ERROR;
    }
    return 0;
}

int bwrite(unsigned int nbloque, const void *buf) {
    return 0;
}
