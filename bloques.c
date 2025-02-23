#include "bloques.h"

static int descriptor = 0;

int bmount(const char *path) {
    //Open virtual device into global descriptor
    descriptor = open(path, O_RDWR | O_CREAT, 0666);
    
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

int offsetIntoVirtualDevice(int offset){
    // Move the file pointer to a specific offset into virtual device
    if (lseek(descriptor, offset, SEEK_SET) == ERROR) {
        perror(RED "Error, lseek");
        printf(RESET);
        bumount();
        return ERROR;
    }
    return SUCCESS;
}

int calculateOffset(int nBloque) {
    // Calculate the byte offset
    return nBloque * BLOCKSIZE;
}

int bwrite(unsigned int nBloque, const void *buf) {
    int offset = calculateOffset(nBloque);

    if (offsetIntoVirtualDevice(offset) == ERROR) {
        return ERROR;
    }
    //Write a block data into the virtual device
    if (write(descriptor, buf, BLOCKSIZE) == ERROR) {
        perror(RED "Error, write");
        printf(RESET);
        return ERROR;
    }

    return BLOCKSIZE;
}

int bread(unsigned int nBloque, void *buf) {
    int offset = calculateOffset(nBloque);

    if (offsetIntoVirtualDevice(offset) == ERROR) {
        return ERROR;
    }
    if (read(descriptor, buf, BLOCKSIZE) == ERROR) {
        perror(RED "Error, read");
        printf(RESET);
        return ERROR;
    }

    return BLOCKSIZE;
}
