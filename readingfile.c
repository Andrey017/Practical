#include <stdio.h>
#include <stdlib.h>

struct paket{
    int i;
    char m[256];
    float f;
};

int main(int argc, char *argv[])
{
    long size;
    struct paket p;
    FILE *pFile;
    pFile= fopen(argv[1], "rb");

    /*The file name is not set*/
    if (argc == 1){
        printf("ERROR");
    }

    /*Open the file*/
    while (fread(&p, sizeof(struct paket), 1, pFile)) {
        printf("%d %s %f\n", p.i, p.m, p.f);
    }

    puts("\n");

    /*File size*/
    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);
    printf("File size: %ld", size);

    fclose(pFile);

    return 0;
}
