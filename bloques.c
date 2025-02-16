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
    //Close virtual device
    if (close(descriptor) == ERROR) {
        perror(RED "Error bumount");
        printf(RESET);
        return ERROR;
    }
    return 0;
}

int bwrite(unsigned int nBloque, const void *buf) {
    int offset = nBloque * BLOCKSIZE;
    
    if (lseek(descriptor, offset, SEEK_SET) == ERROR) {
        perror(RED "Error, lseek");
        printf(RESET);
        bumount();
        return ERROR;
    }

    if (write(descriptor, buf, BLOCKSIZE) == ERROR) {
        perror(RED "Error, write");
        printf(RESET);
        return ERROR;
    }

    return BLOCKSIZE;
}


