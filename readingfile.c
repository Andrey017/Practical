#include <stdio.h>
#include <stdlib.h>

struct paket{
    int i;
    char m[256];
    float f;
};

int main(int argc, char *argv[])
{
    int size;
    struct paket p;
    FILE *pFile;

    /*The file name is not set*/
    if (argc == 1){
        printf("Enter the file name");
        exit(1);
    }

    /*Open the file*/
    else{

        pFile= fopen(argv[1], "rb");

        while (fread(&p, sizeof(struct paket), 1, pFile)) {
            printf("%d %s %f\n", p.i, p.m, p.f);
        }

        /*File size*/
        fseek(pFile, 0, SEEK_END);
        size = ftell(pFile);
        fseek(pFile, 0, SEEK_SET);
        printf("File size: %d%s", size, "\tbytes");

        fclose(pFile);

    }

    return 0;
}
