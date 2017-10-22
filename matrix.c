#include <stdio.h>
#include <stdlib.h>

int **A;
int **C;
int **D;

int main(int argc, char *argv[])
{
    int N, M, i, j, t, k, s, min, di, dj, R, H, Z, y;
    N= atoi(argv[1]);
    M= atoi(argv[2]);
    
    /*Creating the first array*/
    A = (int **) malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        A[i]=(int*)malloc(sizeof(int*)*M);
    }
    if(A == NULL) exit(1);

    
    if (N>3 & M>4){
        for (i=0; i<N; i++){
            for (j=0; j<M; j++){
                A[i][j]= (rand()&(20 - 10 +1));
                printf("\t%d", *(*(A+i)+j));
            }
            puts("\n");
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

    R=N;
    H=M;

    printf("\tEnter the number of columns =");
    scanf("%d", &Z);

    printf("\n");

    /*We introduce the second matrix*/
    C = (int **) malloc(sizeof(int)*H);
    for (i=0; i<H; i++){
        C[i]= (int*) malloc(sizeof(int*)*Z);
    }
    if(C == NULL) exit(1);


    for (i=0; i<H; i++){
        for (j=0; j<Z; j++){
            printf("\tEnter the number [%d][%d] =", i, j);
            scanf("%d", *(C+i)+j);
        }
        puts("\n");
    }

    
    D = (int **) malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        D[i]= (int*) malloc(sizeof(int*)*Z);
    }
    if (D == NULL) exit(1);

    puts("\n");

    /*We multiply the matrices*/
    for(i=0; i<N; i++){
        for (j=0; j<Z; j++){
            D[i][j]=0;
            for (y=0; y<M; y++){
                D[i][j] += A[i][y]*C[y][j];
            }
        }
    }

    printf("Result:");

    /*Output the result*/
    for (i=0; i<N; i++){
        for (j=0; j<Z; j++){
            printf("\t%d", *(*(D+i)+j));
        }
        puts("\n");
    }

    /*Freeing memory*/
    for (i=0; i<N; i++){
        free(A[i]);
        free(C[i]);
        free(D[i]);
    }
    free(A);
    free(C);
    free(D);

    return 0;
}
