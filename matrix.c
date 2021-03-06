#include <stdio.h>
#include <stdlib.h>

int **A;
int **B;
int **C;
int **D;

int main(int argc, char *argv[])
{
    int N, M, i, j, t, k, s, min, di, dj, R, H, Z, y, l=0, p=0;
    if (argc != 3){
        printf("Not enough parameters");
        printf("\nmatrix <number of lines> <number of columns>");
        exit(1);
    }
    N= atoi(argv[1]);
    M= atoi(argv[2]);
    if (N==0 || M==0) exit(1);
    R=N-1;
    H=M-1;

    /*Creating the first array*/
    A = (int **) malloc(sizeof(int)*N);
            for (i=0; i<N; i++){
                A[i]=(int*)malloc(sizeof(int*)*M);
            }
        if(A == NULL){
            printf("Unable to allocate memory");
            exit(1);
        }

    if (N>3){
        if (M>4){
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                A[i][j]= (rand()&(20 - 10 +1));
                printf("\t%d", *(*(A+i)+j));
            }
            puts("\n");
        }
    }
    }
    else{
        printf("Incorrect parameters");
        return -1;
    }

    puts("\n");

    /*Change the first line with the last*/
    for (j=0; j<M; j++){
        t= A[0][j];
        A[0][j]= A[N-1][j];
        A[N-1][j]= t;
    }

    /*Change the elements of the array*/
    for (j=0; j<M; j++){
        k= A[0][j];
        A[0][j]= A[0][M-1];
        A[0][M-1]= k;

        s= A[N-1][j];
        A[N-1][j]= A[N-1][M-1];
        A[N-1][M-1]= s;
        M--;
    }
    M= atoi(argv[2]);
    /*Output the result*/
    for (i=0; i<N; i++){
        for (j=0; j<M; j++){
            printf("\t%d", *(*(A+i)+j));
        }
        puts("\n");
    }
    /*Find the smallest element of the array*/
    for (i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(A[i][j]<=min){
                min= A[i][j];
                di=i;
                dj=j;
            }
        }
    }
    /*Delete the row and the column with the smallest element*/
    B = (int **) malloc(sizeof(int)*N);
            for (l=0; l<N; l++){
                B[l]=(int*)malloc(sizeof(int*)*M);
            }
        if(B == NULL){
            printf("Unable to allocate memory");
            exit(1);
        }

    l=0;
    p=0;

    for(i=0; i<N; i++){
        if (i == di){
            continue;
        }
        for(j=0; j<M; j++){
            if (j == dj){
                continue;
            }
            B[l][p]= A[i][j];
            p++;
        }
        l++;
        p=0;
    }

    for (l=0; l<R; l++){
        for (p=0; p<H; p++){
            printf("\t%d", *(*(B+l)+p));
        }
        puts("\n");
    }

    printf("\tEnter the number of columns =");
    scanf("%d", &Z);

    printf("\n");

    /*We introduce the second matrix*/
    C = (int **) malloc(sizeof(int)*H);
        for (l=0; l<H; l++){
            C[l]= (int*) malloc(sizeof(int*)*Z);
        }
        if(C == NULL){
            printf("Unable to allocate memory");
            exit(1);
        }


    for (l=0; l<H; l++){
        for (p=0; p<Z; p++){
            printf("\tEnter the number [%d][%d] =", l, p);
            scanf("%d", *(C+l)+p);
        }
        puts("\n");
    }


    D = (int **) malloc(sizeof(int)*R);
    for (l=0; l<R; l++){
        D[l]= (int*) malloc(sizeof(int*)*Z);
    }
    if (D == NULL){
        printf("Unable to allocate memory");
        exit(1);
    }

    puts("\n");

    /*We multiply the matrices*/
    for (l=0; l<R; l++){
        for (p=0; p<Z; p++){
            D[l][p]=0;
            for (y=0; y<H; y++){
                D[l][p] += B[l][y]*C[y][p];
            }
        }
    }

    printf("Result:");

    /*Output the result*/
    for (l=0; l<R; l++){
        for (p=0; p<Z; p++){
            printf("\t%d", *(*(D+l)+p));
        }
        puts("\n");
    }

    /*Freeing memory*/
    for (i=0; i<N; i++){
        free(A[i]);
    }
    free(A);

    for (l=0; l<N; l++){
        free(B[l]);
    }
    free(B);

    for (l=0; l<R; l++){
        free(C[l]);
        free(D[l]);
    }
    free(C);
    free(D);

    return 0;
}
