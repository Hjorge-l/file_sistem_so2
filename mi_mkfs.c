#include "bloques.h"
#include "ficheros_basico.h"

int main (int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Error Número de argumentos invalida, solo puedes introducir 2 argumentos\n");
        return ERROR;
    }
    char *path = argv[1];
    int nBloques = atoi(argv[2]);
    unsigned char buf[BLOCKSIZE];

    if (bmount(path) == ERROR) {
        fprintf(stderr, "Error al montar el dispositivo virtuali\n");
        return ERROR;
    }

    if (!memset(buf, 0, BLOCKSIZE)) {
        fprintf(stderr, "Error al reservar memoria con memset");
        return ERROR;
    }

    for (int i = 0; i < nBloques; i++) {
        if (bwrite(i, buf) == ERROR) {
            fprintf(stderr, "Error al escribir un bloque dentro del dispositivo virtual");
            return ERROR;
        }
    }

    if (bumount() == ERROR) {
        fprintf(stderr, "Error al desmontar el dispositivo virtual");
        return ERROR;
    }
    return SUCCESS;
}
